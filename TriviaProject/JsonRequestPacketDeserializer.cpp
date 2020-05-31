#include "JsonRequestPacketDeserializer.h"


// this function serializes a deserializer Buffer and returns the deserialized LoginRequest
LoginRequest JsonRequestPacketDeserializer::deserializeLoginRequest(Buffer buffer)
{
	nlohmann::json json = bufferToJson(buffer);
	return LoginRequest{ json["Username"], json["Password"] };
}

// this function serializes a deserializer Buffer and returns the deserialized SignupRequest
SignupRequest JsonRequestPacketDeserializer::deserializeSignupRequest(Buffer buffer)
{
	nlohmann::json json = bufferToJson(buffer);
	return SignupRequest{ json["Username"], json["Password"], json["Email"], json["Phone"], json["Address"], json["BirthDate"] };
}

// this function serializes a deserializer Buffer and returns the deserialized GetPlayersInRoomRequest
GetPlayersInRoomRequest JsonRequestPacketDeserializer::deserializeGetPlayersRequest(Buffer buffer)
{
	nlohmann::json json = bufferToJson(buffer);
	return GetPlayersInRoomRequest{ (unsigned int)stoi(std::string(json["RoomId"])) };
}

// this function serializes a deserializer Buffer and returns the deserialized JoinRoomRequest
JoinRoomRequest JsonRequestPacketDeserializer::deserializeJoinRoomRequest(Buffer buffer)
{
	nlohmann::json json = bufferToJson(buffer);
	return JoinRoomRequest{ (unsigned int)stoi(std::string(json["RoomId"])) };
}

// this function serializes a deserializer Buffer and returns the deserialized CreateRoomRequest
CreateRoomRequest JsonRequestPacketDeserializer::deserializeCreateRoomRequest(Buffer buffer)
{
	nlohmann::json json = bufferToJson(buffer);
	return CreateRoomRequest{ json["RoomName"], json["MaxUsers"], json["QuestionCount"], json["AnswerTimeout"] };
}

// this function return a json from buffer
nlohmann::json JsonRequestPacketDeserializer::bufferToJson(Buffer buffer)
{
	std::string bufferString(buffer.begin(), buffer.end());
	int size = stoi(bufferString.substr(JSON_SIZE_START_INDEX, JSON_START_INDEX));
	bufferString = bufferString.substr(JSON_START_INDEX, size);
	return nlohmann::json::parse(bufferString);
}
