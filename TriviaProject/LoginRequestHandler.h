#pragma once
#include "IRequestHandler.h"
#include "JsonRequestPacketDeserializer.h"
#include "RequestHandlerFactory.h"

class RequestHandlerFactory;

class LoginRequestHandler : public IRequestHandler
{
private:
	RequestHandlerFactory* m_handlerFactory;
	RequestResult login(RequestInfo infro);
	RequestResult signup(RequestInfo infro);
public:
	LoginRequestHandler();
	bool isRequestRelevant(RequestInfo infro);
	RequestResult handleRequest(RequestInfo infro);
};