#pragma once
#include "LoginManager.h"
#include "LoginRequestHandler.h"
#include "StatisticsManager.h"
#include "MenuRequestHandler.h"
#include "RoomManager.h"

class LoginRequestHandler;
class MenuRequestHandler;

class RequestHandlerFactory
{
private:
	RequestHandlerFactory(); //Private constructor to prevent instancing
	LoginManager m_loginManager;
	StatisticsManager m_StatisticsManager;
	RoomManager m_roomManager;
public:
	static RequestHandlerFactory* getInstance(); // Static access method
	LoginRequestHandler* createLoginRequestHandler();
	MenuRequestHandler* createMenuRequestHandler(std::string);
	LoginManager& getLoginManager();
	StatisticsManager& getStatisticsManager();
	RoomManager& getRoomManager();
};
