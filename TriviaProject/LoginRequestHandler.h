#pragma once
#include "IRequestHandler.h"
#include "JsonRequestPacketDeserializer.h"
#include "RequestHandlerFactory.h"

class RequestHandlerFactory;

class LoginRequestHandler : public IRequestHandler
{
private:
	RequestHandlerFactory* m_handlerFactory;
public:
	LoginRequestHandler();
	~LoginRequestHandler();
	bool isRequestRelevant(RequestInfo infro);
	RequestResult handleRequest(RequestInfo infro);
	RequestResult login(RequestInfo infro);
	RequestResult signup(RequestInfo infro);
};