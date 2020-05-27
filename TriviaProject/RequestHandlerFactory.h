#pragma once
#include "LoginManager.h"
#include "LoginRequestHandler.h"
#include "StatisticsManager.h"
#include "MenuRequestHandler.h"

class LoginRequestHandler;
class MenuRequestHandler;

class RequestHandlerFactory
{
private:
	LoginManager m_loginManager;
	StatisticsManager m_StatisticsManager;

public:
	RequestHandlerFactory();
	LoginRequestHandler* createLoginRequestHandler();
	MenuRequestHandler* createMenuRequestHandler(std::string);
	LoginManager& getLoginManager();
	StatisticsManager& getStatisticsManager();
};