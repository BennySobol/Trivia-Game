#include "LoginRequestHandler.h"


// LoginRequestHandler Constructor
LoginRequestHandler::LoginRequestHandler() : m_handlerFactory(new RequestHandlerFactory()) {}

// LoginRequestHandler Distructor
LoginRequestHandler::~LoginRequestHandler() { delete m_handlerFactory; }

// this function checks if a request is relevant
bool LoginRequestHandler::isRequestRelevant(RequestInfo infro)
{
	return infro.id == (int)MessageCode::LOGIN || infro.id == (int)MessageCode::SIGNUP;
}

// this function handles a request
RequestResult LoginRequestHandler::handleRequest(RequestInfo infro)
{
	if (infro.id == (int)MessageCode::LOGIN)
	{
		return login(infro);
	}
	if (infro.id == (int)MessageCode::SIGNUP)
	{
		return signup(infro);
	}

	ErrorResponse error{ "error - not a valid request" };
	Buffer buffer = JsonResponsePacketSerializer::serializeResponse(error);
	RequestResult requestResult{ buffer, new LoginRequestHandler() };
	return requestResult;
}

// this login function gets a RequestInfo and return RequestResult
RequestResult LoginRequestHandler::login(RequestInfo infro)
{
	LoginRequest signupRequest = JsonRequestPacketDeserializer::deserializeLoginRequest(infro.buffer);

	LoginResponse login{ (int)m_handlerFactory->getLoginManager().login(signupRequest.username, signupRequest.password) };
	Buffer buffer = JsonResponsePacketSerializer::serializeResponse(login);

	return RequestResult{ buffer, new LoginRequestHandler() };
}

// this signup function gets a RequestInfo and return RequestResult
RequestResult LoginRequestHandler::signup(RequestInfo infro)
{
	SignupRequest signupRequest = JsonRequestPacketDeserializer::deserializeSignupRequest(infro.buffer);

	SignupResponse signup{ (int)m_handlerFactory->getLoginManager().signup(signupRequest.username, signupRequest.password, signupRequest.email) };
	Buffer buffer = JsonResponsePacketSerializer::serializeResponse(signup);
	 
	return RequestResult{ buffer, new LoginRequestHandler() };
}