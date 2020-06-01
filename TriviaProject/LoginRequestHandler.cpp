#include "LoginRequestHandler.h"


// LoginRequestHandler Constructor
LoginRequestHandler::LoginRequestHandler() : m_handlerFactory(RequestHandlerFactory::getInstance()) {}

// this function checks if a request is relevant
bool LoginRequestHandler::isRequestRelevant(RequestInfo infro)
{
	return infro.id == (int)MessageCode::LOGIN || infro.id == (int)MessageCode::SIGNUP;
}

// this function handles a request
RequestResult LoginRequestHandler::handleRequest(RequestInfo infro)
{
	switch (infro.id)
	{
	case (int)MessageCode::LOGIN:
		return login(infro);

	case (int)MessageCode::SIGNUP:
		return signup(infro);
	default:
		return RequestResult{ JsonResponsePacketSerializer::serializeResponse(ErrorResponse{ "error - not a valid request" }), m_handlerFactory->createLoginRequestHandler() };
	}
}

// this login function gets a RequestInfo and return RequestResult
RequestResult LoginRequestHandler::login(RequestInfo infro)
{
	LoginRequest loginRequest = JsonRequestPacketDeserializer::deserializeLoginRequest(infro.buffer);

	LoginResponse login{ (unsigned int)m_handlerFactory->getLoginManager().login(loginRequest.username, loginRequest.password) };
	Buffer buffer = JsonResponsePacketSerializer::serializeResponse(login);
	if (login.status == (int)LoginStatus::LOGIN_SUCCESS)
	{
		return RequestResult{ buffer, m_handlerFactory->createMenuRequestHandler(loginRequest.username) };
	}
	return RequestResult{ buffer, NULL };
}

// this signup function gets a RequestInfo and return RequestResult
RequestResult LoginRequestHandler::signup(RequestInfo infro)
{
	SignupRequest signupRequest = JsonRequestPacketDeserializer::deserializeSignupRequest(infro.buffer);

	SignupResponse signup{ (unsigned int)m_handlerFactory->getLoginManager().signup(signupRequest.username, signupRequest.password, signupRequest.email, signupRequest.phone, signupRequest.address, signupRequest.birthDate) };
	Buffer buffer = JsonResponsePacketSerializer::serializeResponse(signup);

	if (signup.status == (int)SignupStatus::SIGNUP_SUCCESS)
	{
		m_handlerFactory->getLoginManager().login(signupRequest.username, signupRequest.password); // auto login for the user it must be valid
		return RequestResult{ buffer, m_handlerFactory->createMenuRequestHandler(signupRequest.username) };
	}
	return RequestResult{ buffer, NULL };
}
