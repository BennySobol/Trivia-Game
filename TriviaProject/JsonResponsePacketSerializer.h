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
} CreateRoomResponse;

typedef struct JoinRoomResponse
{
	unsigned int status;
} JoinRoomResponse;

typedef struct CloseRoomResponse
{
	unsigned int status;
} CloseRoomResponse;

typedef struct StartGameResponse
{
	unsigned int status;
} StartGameResponse;

typedef struct LeaveRoomResponse
{
	unsigned int status;
} LeaveRoomResponse;

typedef struct GetRoomStateResponse
{
	unsigned int status;
	bool hasGameBegun;
	nlohmann::json players;
	unsigned int questionCount;
	unsigned int answerTimeout;
} GetRoomStateResponse;

typedef struct LeaveGameResponse
{
	unsigned int status;
} LeaveGameResponse;

typedef struct GetQuestionResponse
{
	unsigned int status;
	std::string question;
	nlohmann::json answers;
} GetQuestionResponse;

typedef struct SubmitAnswerResponse
{
	unsigned int status;
	bool isCorrectAnswer;
} SubmitAnswerResponse;

typedef struct PlayerResults
{
	std::string username;
	unsigned int correctAnswerCount;
	unsigned int wrongAnswerCount;
	unsigned int averageAnswerTime;
} PlayerResults;

typedef struct GetGameResultsResponse
{
	unsigned int status;
	std::vector<PlayerResults> results;
} GetGameResultsResponse;

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
	static Buffer serializeResponse(CloseRoomResponse closeRoom);
	static Buffer serializeResponse(StartGameResponse startGame);
	static Buffer serializeResponse(GetRoomStateResponse getRoomState);
	static Buffer serializeResponse(LeaveRoomResponse leaveRoom);
	static Buffer serializeResponse(GetGameResultsResponse getGameResults);
	static Buffer serializeResponse(SubmitAnswerResponse submitAnswer);
	static Buffer serializeResponse(GetQuestionResponse getQuestion);
	static Buffer serializeResponse(LeaveGameResponse leaveGame);
	static std::string getPaddedNumber(int num, int digits);
};
