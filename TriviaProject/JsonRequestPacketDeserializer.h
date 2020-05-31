#pragma once
#include "json.hpp"
#include <iostream>
#include <vector>

typedef unsigned char byte;
typedef std::vector<byte> Buffer;

#define JSON_START_INDEX 6
#define JSON_SIZE_START_INDEX 1

typedef struct LoginRequest
{
	std::string username;
	std::string password;
} LoginRequest;

typedef struct SignupRequest
{
	std::string username;
	std::string password;
	std::string email;
	std::string phone;
	std::string address;
	std::string birthDate;
} SignupRequest;

typedef struct CreateRoomRequest
{
	std::string roomName;
	unsigned int maxUsers;
	unsigned int questionCount;
	unsigned int answerTimeout;
} CreateRoomRequest;

typedef struct JoinRoomRequest
{
	unsigned int roomId;
} JoinRoomRequest;

typedef struct GetPlayersInRoomRequest
{
	unsigned int roomId;
} GetPlayersInRoomRequest;


class JsonRequestPacketDeserializer
{
public:
	static LoginRequest deserializeLoginRequest(Buffer);
	static SignupRequest deserializeSignupRequest(Buffer);
	static GetPlayersInRoomRequest deserializeGetPlayersRequest(Buffer buffer);
	static JoinRoomRequest deserializeJoinRoomRequest(Buffer buffer);
	static CreateRoomRequest deserializeCreateRoomRequest(Buffer buffer);
	static nlohmann::json bufferToJson(Buffer buffer);
};
