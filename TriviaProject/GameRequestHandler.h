#pragma once
#include "IRequestHandler.h"
#include "RequestHandlerFactory.h"

class RequestHandlerFactory;

class GameRequestHandler : public IRequestHandler
{
private:
	LoggedUser m_user;
	Game* m_game;
	RequestHandlerFactory* m_handlerFactory;
	RequestResult getQuestion(RequestInfo info);
	RequestResult submitAnswer(RequestInfo info);
	RequestResult getGameResults(RequestInfo info);
	RequestResult leaveGame(RequestInfo info);

public:
	GameRequestHandler(std::string username, Game* game);
	bool isRequestRelevant(RequestInfo);
	RequestResult handleRequest(RequestInfo);
};
