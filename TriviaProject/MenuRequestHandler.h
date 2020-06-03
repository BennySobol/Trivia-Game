#pragma once
#include "IRequestHandler.h"
#include "RequestHandlerFactory.h"

class RequestHandlerFactory;

class MenuRequestHandler : public IRequestHandler
{
private:
	LoggedUser m_user;
	RequestHandlerFactory* m_handlerFactory;
	RequestResult getStatistics(RequestInfo infro);
	RequestResult signout(RequestInfo infro);
	RequestResult getRooms(RequestInfo infro);
	RequestResult getPlayersInRoom(RequestInfo infro);
	RequestResult joinRoom(RequestInfo infro);
	RequestResult createRoom(RequestInfo infro);

public:
	MenuRequestHandler(std::string);
	bool isRequestRelevant(RequestInfo infro);
	RequestResult handleRequest(RequestInfo infro);
};