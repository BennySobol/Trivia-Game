#include "JsonRequestPacketDeserializer.h"


// this function serializes a deserializer Buffer and returns the deserialized LoginRequest
LoginRequest JsonRequestPacketDeserializer::deserializeLoginRequest(Buffer buffer)
{
	nlohmann::json json = bufferToJson(buffer);
	return LoginRequest{ json["username"], json["password"] };
}

// this function serializes a deserializer Buffer and returns the deserialized SignupRequest
SignupRequest JsonRequestPacketDeserializer::deserializeSignupRequest(Buffer buffer)
{
	nlohmann::json json = bufferToJson(buffer);
	return SignupRequest{ json["username"], json["password"], json["email"], json["phone"], json["address"], json["birthDate"] };
}


// this function return a json from buffer
nlohmann::json JsonRequestPacketDeserializer::bufferToJson(Buffer buffer)
{
	std::string bufferString(buffer.begin(), buffer.end());
	int size = stoi(bufferString.substr(JSON_SIZE_START_INDEX, JSON_START_INDEX));
	bufferString = bufferString.substr(JSON_START_INDEX, size);
	return nlohmann::json::parse(bufferString);
}