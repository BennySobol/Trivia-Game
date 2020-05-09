#include "JsonResponsePacketSerializer.h"

// return string after padding zeros if necessary
std::string JsonResponsePacketSerializer::getPaddedNumber(int num, int digits)
{
	std::ostringstream ostr;
	ostr << std::setw(digits) << std::setfill('0') << num;
	return ostr.str();
}

// this function return a Buffer that represent a json and a message code
Buffer JsonResponsePacketSerializer::serializeResponse(unsigned char code, nlohmann::json json)
{
	Buffer jsonBuffer;
	std::string serializedString = json.dump(); // serialize json to string 
	jsonBuffer.insert(jsonBuffer.begin(), serializedString.begin(), serializedString.end()); // insert the string to the Buffer							
    jsonBuffer.insert(jsonBuffer.begin(), code); // insert the message code at start
	std::string messagLength = getPaddedNumber(jsonBuffer.size(), 4);
	jsonBuffer.insert(++jsonBuffer.begin(), messagLength.begin(), messagLength.end()); // insert the json length
	return jsonBuffer;
}

// this function serializes a ErrorResponse struct and returns the serialized Buffer
Buffer JsonResponsePacketSerializer::serializeResponse(ErrorResponse error)
{
	nlohmann::json json = nlohmann::json{ {"message", error.message} };
	Buffer buffer = serializeResponse(char(MessageCode::ERROR_MESSAGE), json);
	return buffer;
}

// this function serializes a LoginResponse struct and returns the serialized Buffer
Buffer JsonResponsePacketSerializer::serializeResponse(LoginResponse login)
{
	nlohmann::json json = nlohmann::json::object({ {"status", login.status} });
	Buffer buffer = serializeResponse(char(MessageCode::LOGIN), json);
	return buffer;
}

// this function serializes a SignupResponse struct and returns the serialized Buffer
Buffer JsonResponsePacketSerializer::serializeResponse(SignupResponse singup)
{
	nlohmann::json json = nlohmann::json{ {"status", singup.status} };
	Buffer buffer = serializeResponse(char(MessageCode::SIGNUP), json);
	return buffer;
}