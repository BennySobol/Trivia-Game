#include "RequestHandlerFactory.h"

// RequestHandlerFactory Constructor
RequestHandlerFactory::RequestHandlerFactory() : m_loginManager(), m_StatisticsManager() {};

// get RequestHandlerFactory Instance - a Singleton class
RequestHandlerFactory* RequestHandlerFactory::getInstance()
{
	static RequestHandlerFactory instance;

	return &instance;
}

// create and return a new LoginRequestHandler
LoginRequestHandler* RequestHandlerFactory::createLoginRequestHandler()
{
	return new LoginRequestHandler();
}

// get m_loginManager
LoginManager& RequestHandlerFactory::getLoginManager()
{
	return m_loginManager;
}

// create and return a new MenuRequestHandler
MenuRequestHandler* RequestHandlerFactory::createMenuRequestHandler(std::string username)
{
	return new MenuRequestHandler(username);
}

// get m_StatisticsManager
StatisticsManager& RequestHandlerFactory::getStatisticsManager()
{
	return m_StatisticsManager;
}

// get m_roomManager
RoomManager& RequestHandlerFactory::getRoomManager()
{
	return m_roomManager;
}
