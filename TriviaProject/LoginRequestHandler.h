#pragma once
#include "IRequestHandler.h"
#include "JsonRequestPacketDeserializer.h"
#include "RequestHandlerFactory.h"

class RequestHandlerFactory;

class LoginRequestHandler : public IRequestHandler
{
private:
	RequestHandlerFactory* m_handlerFactory;
	RequestResult login(RequestInfo info);
	RequestResult signup(RequestInfo info);
public:
	LoginRequestHandler();
	bool isRequestRelevant(RequestInfo info);
	RequestResult handleRequest(RequestInfo info);
};