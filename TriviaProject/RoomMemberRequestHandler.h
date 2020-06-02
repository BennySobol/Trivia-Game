#pragma once
#include "IRequestHandler.h"
#include "RequestHandlerFactory.h"

class RequestHandlerFactory;

class RoomMemberRequestHandler : public IRequestHandler
{
private:
	unsigned int m_roomId;
	LoggedUser m_user;
	RequestHandlerFactory* m_handlerFactory;
	RequestResult leaveRoom(RequestInfo);
	RequestResult getRoomState(RequestInfo);
public:
	RoomMemberRequestHandler(unsigned int roomId, std::string username);
	bool isRequestRelevant(RequestInfo infro);
	RequestResult handleRequest(RequestInfo infro);
};