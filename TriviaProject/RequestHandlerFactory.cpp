#include "RequestHandlerFactory.h"

// RequestHandlerFactory Constructor
RequestHandlerFactory::RequestHandlerFactory() : m_loginManager(), m_StatisticsManager(), m_roomManager() {};

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

// create and return a new RoomAdminRequestHandler
RoomAdminRequestHandler* RequestHandlerFactory::createRoomAdminRequestHandler(int roomId, std::string username)
{
	return new RoomAdminRequestHandler(roomId, username);
}

// create and return a new RoomMemberRequestHandler
RoomMemberRequestHandler* RequestHandlerFactory::createRoomMemberRequestHandler(int roomId, std::string username)
{
	return new RoomMemberRequestHandler(roomId, username);
}

// create and return a new GameRequestHandler
GameRequestHandler* RequestHandlerFactory::createGameRequestHandler(std::string username, Game* game)
{
	return new GameRequestHandler(username, game);
}

// get m_gameManager
GameManager& RequestHandlerFactory::getGameManager()
{
	return m_gameManager;
}