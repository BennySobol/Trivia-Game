#pragma once
#include "LoginManager.h"
#include "LoginRequestHandler.h"
#include "StatisticsManager.h"
#include "MenuRequestHandler.h"
#include "RoomManager.h"
#include "RoomAdminRequestHandler.h"
#include "RoomMemberRequestHandler.h"
#include "GameManager.h"
#include "GameRequestHandler.h"

class LoginRequestHandler;
class MenuRequestHandler;
class RoomAdminRequestHandler;
class RoomMemberRequestHandler;
class GameRequestHandler;

class RequestHandlerFactory
{
private:
	RequestHandlerFactory(); //Private constructor to prevent instancing
	LoginManager m_loginManager;
	StatisticsManager m_StatisticsManager;
	RoomManager m_roomManager;
	GameManager m_gameManager;
public:
	static RequestHandlerFactory* getInstance(); // Static access method
	LoginRequestHandler* createLoginRequestHandler();
	MenuRequestHandler* createMenuRequestHandler(std::string);
	LoginManager& getLoginManager();
	StatisticsManager& getStatisticsManager();
	RoomManager& getRoomManager();
	RoomAdminRequestHandler* createRoomAdminRequestHandler(int roomId, std::string username);
	RoomMemberRequestHandler * createRoomMemberRequestHandler(int roomId, std::string username);
	GameRequestHandler* createGameRequestHandler(std::string username, Game game);
	GameManager& getGameManager();
};
