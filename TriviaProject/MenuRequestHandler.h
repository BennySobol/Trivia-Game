#pragma once
#include "IRequestHandler.h"
#include "RequestHandlerFactory.h"

#define MIN_ROOM_NAME_LENGTH 4
#define MAX_PLAYERS_IN_GAME 10
#define MAX_ANSWER_TIMEOUT 60
#define MAX_QUESTION_COUNT 50

class RequestHandlerFactory; // class forward declaration

class MenuRequestHandler : public IRequestHandler
{
private:
	LoggedUser m_user;
	RequestHandlerFactory* m_handlerFactory;
	RequestResult getStatistics(RequestInfo info);
	RequestResult signout(RequestInfo info);
	RequestResult getRooms(RequestInfo info);
	RequestResult getPlayersInRoom(RequestInfo info);
	RequestResult joinRoom(RequestInfo info);
	RequestResult createRoom(RequestInfo info);
public:
	MenuRequestHandler(std::string);
	bool isRequestRelevant(RequestInfo info);
	RequestResult handleRequest(RequestInfo info);
};