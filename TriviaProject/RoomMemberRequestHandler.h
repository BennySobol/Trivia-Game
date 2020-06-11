#pragma once
#include "IRequestHandler.h"
#include "RequestHandlerFactory.h"

class RequestHandlerFactory; // class forward declaration

class RoomMemberRequestHandler : public IRequestHandler
{
private:
	unsigned int m_roomId;
	LoggedUser m_user;
	RequestHandlerFactory* m_handlerFactory;
	RequestResult leaveRoom(RequestInfo info);
	RequestResult getRoomState(RequestInfo info);
public:
	RoomMemberRequestHandler(unsigned int roomId, std::string username);
	bool isRequestRelevant(RequestInfo info);
	RequestResult handleRequest(RequestInfo info);
};