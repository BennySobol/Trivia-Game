#include "JsonResponsePacketSerializer.h"

// return string after padding zeros if necessary
std::string JsonResponsePacketSerializer::getPaddedNumber(int num, int digits)
{
	std::ostringstream ostr;
	ostr << std::setw(digits) << std::setfill(ZERO) << num;
	return ostr.str();
}

// this function return a Buffer that represent a json and a message code
Buffer JsonResponsePacketSerializer::serializeResponse(unsigned char code, nlohmann::json json)
{
	Buffer jsonBuffer;
	std::string serializedString = json.dump(); // serialize json to string 
	jsonBuffer.insert(jsonBuffer.begin(), serializedString.begin(), serializedString.end()); // insert the string to the Buffer							
    jsonBuffer.insert(jsonBuffer.begin(), code); // insert the message code at start
	std::string messagLength = getPaddedNumber(jsonBuffer.size(), RESPONSE_JSON_START_INDEX);
	jsonBuffer.insert(++jsonBuffer.begin(), messagLength.begin(), messagLength.end()); // insert the json length
	return jsonBuffer;
}

// this function serializes a ErrorResponse struct and returns the serialized Buffer
Buffer JsonResponsePacketSerializer::serializeResponse(ErrorResponse error)
{
	nlohmann::json json = nlohmann::json{ "Message", error.message };
	Buffer buffer = serializeResponse(char(MessageCode::ERROR_MESSAGE), json);
	return buffer;
}

// this function serializes a LoginResponse struct and returns the serialized Buffer
Buffer JsonResponsePacketSerializer::serializeResponse(LoginResponse login)
{
	nlohmann::json json = nlohmann::json::object({ { "Status", login.status } });
	Buffer buffer = serializeResponse(char(MessageCode::LOGIN), json);
	return buffer;
}

// this function serializes a SignupResponse struct and returns the serialized Buffer
Buffer JsonResponsePacketSerializer::serializeResponse(SignupResponse singup)
{
	nlohmann::json json = nlohmann::json{ { "Status", singup.status } };
	Buffer buffer = serializeResponse(char(MessageCode::SIGNUP), json);
	return buffer;
}

// this function serializes a GetStatisticsResponse struct and returns the serialized Buffer
Buffer JsonResponsePacketSerializer::serializeResponse(GetStatisticsResponse statistics)
{
	nlohmann::json json = nlohmann::json{ statistics.statistics };
	json.push_back({ "Status", statistics.status });
	Buffer buffer = serializeResponse(char(MessageCode::STATISTICS), json);
	return buffer;
}

// this function serializes a LogoutResponse struct and returns the serialized Buffer
Buffer JsonResponsePacketSerializer::serializeResponse(LogoutResponse logout)
{
	nlohmann::json json = nlohmann::json{ { "Status", logout.status } };
	Buffer buffer = serializeResponse(char(MessageCode::LOGOUT), json);
	return buffer;
}

// this function serializes a GetRoomsResponse struct and returns the serialized Buffer
Buffer JsonResponsePacketSerializer::serializeResponse(GetRoomsResponse getRooms)
{
	nlohmann::json json = nlohmann::json{ getRooms.rooms};
	json.push_back({ "Status", getRooms.status });
	Buffer buffer = serializeResponse(char(MessageCode::GET_ROOMS), json);
	return buffer;
}

// this function serializes a GetPlayersInRoomResponse struct and returns the serialized Buffer
Buffer JsonResponsePacketSerializer::serializeResponse(GetPlayersInRoomResponse getPlayersInRoom)
{
	nlohmann::json json = nlohmann::json{ getPlayersInRoom.playersInRoom };
	Buffer buffer = serializeResponse(char(MessageCode::LOGOUT), json);
	return buffer;
}

// this function serializes a JoinRoomResponse struct and returns the serialized Buffer
Buffer JsonResponsePacketSerializer::serializeResponse(JoinRoomResponse joinRoom)
{
	nlohmann::json json = nlohmann::json{ { "Status", joinRoom.status } };
	Buffer buffer = serializeResponse(char(MessageCode::LOGOUT), json);
	return buffer;
}

// this function serializes a CreateRoomResponse struct and returns the serialized Buffer
Buffer JsonResponsePacketSerializer::serializeResponse(CreateRoomResponse createRoom)
{
	nlohmann::json json = nlohmann::json{ { "Status", createRoom.status }, {"RoomId", createRoom.roomId} };
	Buffer buffer = serializeResponse(char(MessageCode::LOGOUT), json);
	return buffer;
}
