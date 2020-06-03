#pragma once
#include "IRequestHandler.h"
#include "RequestHandlerFactory.h"

class RequestHandlerFactory;

class RoomAdminRequestHandler : public IRequestHandler
{
private:
	unsigned int m_roomId;
	LoggedUser m_user;
	RequestHandlerFactory* m_handlerFactory;
	RequestResult closeRoom(RequestInfo);
	RequestResult startGame(RequestInfo);
	RequestResult getRoomState(RequestInfo);
public:
	RoomAdminRequestHandler(unsigned int m_roomId, std::string username);
	bool isRequestRelevant(RequestInfo infro);
	RequestResult handleRequest(RequestInfo infro);
};