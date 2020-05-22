#pragma once
#include "LoginManager.h"
#include "LoginRequestHandler.h"
class LoginRequestHandler;

class RequestHandlerFactory
{
public:
	RequestHandlerFactory();
	LoginRequestHandler* createLoginRequestHandler();
	LoginManager& getLoginManager();

private:
	LoginManager m_loginManager;
};