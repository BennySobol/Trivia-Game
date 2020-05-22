#include "LoginRequestHandler.h"
#include "JsonRequestPacketDeserializer.h"

// this function checks if a request is relevant
bool LoginRequestHandler::isRequestRelevant(RequestInfo infro)
{
	return infro.id == (int)MessageCode::LOGIN || infro.id == (int)MessageCode::SIGNUP;
}

// this function handle a request
RequestResult LoginRequestHandler::handleRequest(RequestInfo infro)
{
	if (infro.id == (int)MessageCode::LOGIN)
	{
		LoginRequest  loginRequest = JsonRequestPacketDeserializer::deserializeLoginRequest(infro.buffer);

		ErrorResponse error{ "Error - Login not implemented" };
		Buffer buffer = JsonResponsePacketSerializer::serializeResponse(error);

		RequestResult requestResult{ buffer, new LoginRequestHandler() };
		return requestResult;
	}
	if (infro.id == (int)MessageCode::SIGNUP)
	{
		SignupRequest signupRequest = JsonRequestPacketDeserializer::deserializeSignupRequest(infro.buffer);

		ErrorResponse error{ "Error - Signup not implemented" };
		Buffer buffer = JsonResponsePacketSerializer::serializeResponse(error);

		RequestResult requestResult{ buffer, new LoginRequestHandler()};
		return requestResult;
	}

	ErrorResponse error{ "error - not a valid request" };
	Buffer buffer = JsonResponsePacketSerializer::serializeResponse(error);

	RequestResult requestResult{ buffer, new LoginRequestHandler() };
	return requestResult;
}