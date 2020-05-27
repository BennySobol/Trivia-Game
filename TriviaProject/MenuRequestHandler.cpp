#include "MenuRequestHandler.h"

// MenuRequestHandler Constructor
MenuRequestHandler::MenuRequestHandler(std::string username) : m_handlerFactory(new RequestHandlerFactory()), m_user(username){}

// MenuRequestHandler Distructor
MenuRequestHandler::~MenuRequestHandler() { delete m_handlerFactory; }

// this function checks if a request is relevant
bool MenuRequestHandler::isRequestRelevant(RequestInfo infro)
{
	return infro.id == (int)MessageCode::STATISTICS;
}

// this function handles a request
RequestResult MenuRequestHandler::handleRequest(RequestInfo infro)
{
	if (infro.id == (int)MessageCode::STATISTICS)
	{
		return getStatistics(infro);
	}

	ErrorResponse error{ "error - not a valid request" };
	Buffer buffer = JsonResponsePacketSerializer::serializeResponse(error);
	RequestResult requestResult{ buffer, m_handlerFactory->createMenuRequestHandler(m_user.getUsername()) };
	return requestResult;
}

// this statistics function gets a RequestInfo and return RequestResult
RequestResult MenuRequestHandler::getStatistics(RequestInfo infro)
{
	unsigned int status = (int)StatisticsStatus::STATISTICS_SUCCESS;
	nlohmann::json json = m_handlerFactory->getStatisticsManager().getStatistics(m_user.getUsername());
	if (json.is_null())
		status = (int)StatisticsStatus::STATISTICS_ERROR;
	GetStatisticsResponse statistics{ status, json };
	Buffer buffer = JsonResponsePacketSerializer::serializeResponse(statistics);
	return RequestResult{ buffer, m_handlerFactory->createMenuRequestHandler(m_user.getUsername()) };
}
