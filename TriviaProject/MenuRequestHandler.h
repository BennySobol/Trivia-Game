#pragma once
#include "IRequestHandler.h"
#include "RequestHandlerFactory.h"

class RequestHandlerFactory;

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