#pragma once
#include "IRequestHandler.h"

class LoginRequestHandler : public IRequestHandler
{
private:

public:
	LoginRequestHandler() = default;
	bool isRequestRelevant(RequestInfo infro);
	RequestResult handleRequest(RequestInfo infro);
};