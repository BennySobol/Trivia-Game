#pragma once
#include "IRequestHandler.h"
#include "LoggedUser.h"
#include "RequestHandlerFactory.h"

class RequestHandlerFactory;

class MenuRequestHandler : public IRequestHandler
{
private:
	LoggedUser m_user;
	RequestHandlerFactory* m_handlerFactory;

public:
	MenuRequestHandler(std::string);
	~MenuRequestHandler();
	bool isRequestRelevant(RequestInfo infro);
	RequestResult handleRequest(RequestInfo infro);
	RequestResult getStatistics(RequestInfo infro);
	RequestResult signout(RequestInfo infro);
};