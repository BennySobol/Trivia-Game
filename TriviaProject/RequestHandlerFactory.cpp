#include "RequestHandlerFactory.h"

// RequestHandlerFactory Constructor
RequestHandlerFactory::RequestHandlerFactory() : m_loginManager() {};

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