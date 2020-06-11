#pragma once
#include "IRequestHandler.h"
#include "RequestHandlerFactory.h"

class RequestHandlerFactory; // class forward declaration

class RoomAdminRequestHandler : public IRequestHandler
{
private:
	unsigned int m_roomId;
	LoggedUser m_user;
	RequestHandlerFactory* m_handlerFactory;
	RequestResult closeRoom(RequestInfo info);
	RequestResult startGame(RequestInfo info);
	RequestResult getRoomState(RequestInfo info);
public:
	RoomAdminRequestHandler(unsigned int m_roomId, std::string username);
	bool isRequestRelevant(RequestInfo info);
	RequestResult handleRequest(RequestInfo info);
};