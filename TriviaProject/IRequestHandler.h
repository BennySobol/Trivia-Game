#pragma once
#include "JsonResponsePacketSerializer.h"
#include <ctime>
#include <vector>
#include <ostream>

enum class RequestId {LOGIN = 0, SING_UP};

class IRequestHandler; // class forward declaration

typedef struct RequestInfo
{
	RequestId id;
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