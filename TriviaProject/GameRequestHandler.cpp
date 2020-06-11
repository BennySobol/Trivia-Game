#include "GameRequestHandler.h"

// GameRequestHandler constructor
GameRequestHandler::GameRequestHandler(std::string username, Game* game) : m_handlerFactory(RequestHandlerFactory::getInstance()), m_user(username), m_game(game) { }

// this function checks if a request is relevant
bool GameRequestHandler::isRequestRelevant(RequestInfo info)
{
	return info.id == (int)MessageCode::GET_QUESTION || info.id == (int)MessageCode::SUBMIT_ANSWER || info.id == (int)MessageCode::GET_GAME_RESULT || info.id == (int)MessageCode::LEAVE_GAME;
}

// this function handles a request
RequestResult GameRequestHandler::handleRequest(RequestInfo info)
{
	switch (info.id)
	{
	case (int)MessageCode::GET_QUESTION:
		return getQuestion(info);

	case (int)MessageCode::SUBMIT_ANSWER:
		return submitAnswer(info);

	case (int)MessageCode::GET_GAME_RESULT:
		return getGameResults(info);

	case (int)MessageCode::LEAVE_GAME:
		return leaveGame(info);

	default:
		return RequestResult{ JsonResponsePacketSerializer::serializeResponse(ErrorResponse{ "error - not a valid request" }), m_handlerFactory->createMenuRequestHandler(m_user.getUsername()) };
	}
}

// this getQuestion function gets a RequestInfo and return RequestResult
RequestResult GameRequestHandler::getQuestion(RequestInfo info)
{
	Question question = m_game->getQuestionForUser(m_user);
	GetQuestionResponse getQuestion{ SUCCESS_STATUS, question.getQuestion(), question.getPossibleAnswers()};
	Buffer buffer = JsonResponsePacketSerializer::serializeResponse(getQuestion);
	return RequestResult{ buffer, NULL };
}

// this submitAnswer function gets a RequestInfo and return RequestResult
RequestResult GameRequestHandler::submitAnswer(RequestInfo info)
{
	SubmitAnswerRequest submitAnswerRequest = JsonRequestPacketDeserializer::deserializeLSubmitAnswerRequest(info.buffer);
	SubmitAnswerResponse submitAnswer{ SUCCESS_STATUS, m_game->submitAnswer(m_user ,submitAnswerRequest.answerId) };
	Buffer buffer = JsonResponsePacketSerializer::serializeResponse(submitAnswer);
	return RequestResult{ buffer, NULL };
}

// this getGameResults function gets a RequestInfo and return RequestResult
RequestResult GameRequestHandler::getGameResults(RequestInfo info)
{	nlohmann::json json = m_game->getGameResults();
	GetGameResultsResponse getGameResults{ !json["Results"].is_null(), json };
	Buffer buffer = JsonResponsePacketSerializer::serializeResponse(getGameResults);
	if (getGameResults.status)
	{
		m_handlerFactory->getGameManager().addGameToStatistics(*m_game, m_user.getUsername());
		return RequestResult{ buffer, m_handlerFactory->createMenuRequestHandler(m_user.getUsername()) };
	}
	return RequestResult{ buffer, NULL };
}

// this leaveGame function gets a RequestInfo and return RequestResult
RequestResult GameRequestHandler::leaveGame(RequestInfo info)
{
	m_handlerFactory->getGameManager().addGameToStatistics(*m_game, m_user.getUsername());
	LeaveGameResponse leaveGame{ m_game->removePlayer(m_user.getUsername()) };
	Buffer buffer = JsonResponsePacketSerializer::serializeResponse(leaveGame);
	return RequestResult{ buffer, m_handlerFactory->createMenuRequestHandler(m_user.getUsername()) };
}