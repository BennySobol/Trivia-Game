#include "GameRequestHandler.h"

GameRequestHandler::GameRequestHandler(std::string username, Game game) : m_handlerFactory(RequestHandlerFactory::getInstance()), m_user(username), m_game(game) {}

bool GameRequestHandler::isRequestRelevant(RequestInfo info)
{
	return info.id == (int)MessageCode::GET_QUESTION || info.id == (int)MessageCode::SUBMIT_ANSWER || info.id == (int)MessageCode::GET_GAME_RESULT || info.id == (int)MessageCode::LEAVE_GAME;
}

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

RequestResult GameRequestHandler::getQuestion(RequestInfo info)
{
	Question question = m_game.getQuestionForUser(m_user);
	GetQuestionResponse getQuestion{ 1, question.getQuestion(), question.getPossibleAnswers()};
	Buffer buffer = JsonResponsePacketSerializer::serializeResponse(getQuestion);
	return RequestResult{ buffer, NULL };
}

RequestResult GameRequestHandler::submitAnswer(RequestInfo info)
{
	SubmitAnswerRequest submitAnswerRequest = JsonRequestPacketDeserializer::deserializeLSubmitAnswerRequest(info.buffer);
	SubmitAnswerResponse submitAnswer{ 1, m_game.submitAnswer(m_user ,submitAnswerRequest.answerId) };
	Buffer buffer = JsonResponsePacketSerializer::serializeResponse(submitAnswer);
	return RequestResult{ buffer, NULL };
}

RequestResult GameRequestHandler::getGameResults(RequestInfo info)
{
	GetGameResultsResponse getGameResults{ }; ///////// need to do
	Buffer buffer = JsonResponsePacketSerializer::serializeResponse(getGameResults);
	return RequestResult{ buffer, NULL };
}

RequestResult GameRequestHandler::leaveGame(RequestInfo info)
{
	LeaveGameResponse leaveGame{ m_game.removePlayer(m_user.getUsername()) };
	Buffer buffer = JsonResponsePacketSerializer::serializeResponse(leaveGame);
	return RequestResult{ buffer, m_handlerFactory->createMenuRequestHandler(m_user.getUsername()) };
}