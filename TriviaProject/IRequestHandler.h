#pragma once
#include "JsonResponsePacketSerializer.h"
#include <ctime>

class IRequestHandler; // class forward declaration

typedef struct RequestInfo
{
	unsigned int id;
	time_t receivalTime;
	Buffer buffer;
} RequestInfo;

typedef struct RequestResult
{
	Buffer response;
	IRequestHandler * newHandler;
} RequestResult;

class IRequestHandler
{
public:
	IRequestHandler() = default;
	virtual bool isRequestRelevant(RequestInfo infro) = 0;
	virtual RequestResult handleRequest(RequestInfo infro) = 0;
};
