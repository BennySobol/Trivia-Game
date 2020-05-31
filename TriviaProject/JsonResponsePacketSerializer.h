#pragma once
#include "json.hpp"
#include "CodeProtocol.h"
#include "Room.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <sstream>


typedef unsigned char byte;
typedef std::vector<byte> Buffer;

#define RESPONSE_JSON_START_INDEX 4
#define ZERO '0'

typedef struct ErrorResponse 
{
    std::string  message;
} ErrorResponse; 

typedef struct LoginResponse
{
	unsigned int status;
} LoginResponse;

typedef struct SignupResponse
{
	unsigned int status;
} SignupResponse;

typedef struct GetStatisticsResponse
{
	unsigned int status;
	nlohmann::json statistics;
} GetStatisticsResponse;

typedef struct LogoutResponse
{
	unsigned int status;
} LogoutResponse;

typedef struct GetRoomsResponse
{
	unsigned int status;
	nlohmann::json rooms;
} GetRoomsResponse;

typedef struct GetPlayersInRoomResponse
{
	nlohmann::json playersInRoom;
} GetPlayersInRoomResponse;

typedef struct CreateRoomResponse
{
	unsigned int status;
	unsigned int roomId;
} CreateRoomResponse;

typedef struct JoinRoomResponse
{
	unsigned int status;
} JoinRoomResponse;


class JsonResponsePacketSerializer
{
public:
	static Buffer serializeResponse(unsigned char code, nlohmann::json json);
	static Buffer serializeResponse(ErrorResponse error);
	static Buffer serializeResponse(LoginResponse login);
	static Buffer serializeResponse(SignupResponse singup);
	static Buffer serializeResponse(GetStatisticsResponse statistics);
	static Buffer serializeResponse(LogoutResponse logout);
	static Buffer serializeResponse(GetRoomsResponse getRooms);
	static Buffer serializeResponse(GetPlayersInRoomResponse getPlayersInRoom);
	static Buffer serializeResponse(JoinRoomResponse joinRoom);
	static Buffer serializeResponse(CreateRoomResponse createRoom);
	static std::string getPaddedNumber(int num, int digits);
};
