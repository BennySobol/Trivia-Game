#pragma once
#include "IRequestHandler.h"

class RequestHandlerFactory;

class MenuRequestHandler : public IRequestHandler
{
private:
	
public:
	bool isRequestRelevant(RequestInfo infro);
	RequestResult handleRequest(RequestInfo infro);
};