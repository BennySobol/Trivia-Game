#include "MenuRequestHandler.h"
bool MenuRequestHandler::isRequestRelevant(RequestInfo infro)
{
	return true;
}

RequestResult MenuRequestHandler::handleRequest(RequestInfo infro)
{
	Buffer buffer = JsonResponsePacketSerializer::serializeResponse(ErrorResponse{ "Error MenuRequestHandler is not implemented"});
	return RequestResult{ buffer, new MenuRequestHandler() };
}