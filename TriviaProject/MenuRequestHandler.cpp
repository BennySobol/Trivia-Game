#include "MenuRequestHandler.h"

// MenuRequestHandler Constructor
MenuRequestHandler::MenuRequestHandler(std::string username) : m_handlerFactory(RequestHandlerFactory::getInstance()), m_user(username){}

// this function checks if a request is relevant
bool MenuRequestHandler::isRequestRelevant(RequestInfo infro)
{
	return infro.id == (int)MessageCode::STATISTICS || infro.id == (int)MessageCode::LOGOUT;
}

// this function handles a request
RequestResult MenuRequestHandler::handleRequest(RequestInfo infro)
{
	switch (infro.id)
	{
	case (int)MessageCode::STATISTICS:
		return getStatistics(infro);

	case (int)MessageCode::LOGOUT:
		return signout(infro);

	case (int)MessageCode::CREATE_ROOM:
		return createRoom(infro);

	case (int)MessageCode::GET_PLAYERS_IN_ROOM:
		return getPlayersInRoom(infro);

	case (int)MessageCode::GET_ROOMS:
		return getRooms(infro);

	case (int)MessageCode::JOIN_ROOM:
		return joinRoom(infro);

	default:
		return RequestResult{ JsonResponsePacketSerializer::serializeResponse(ErrorResponse{ "error - not a valid request" }), m_handlerFactory->createMenuRequestHandler(m_user.getUsername()) };
	}
}

// this statistics function gets a RequestInfo and return RequestResult
RequestResult MenuRequestHandler::getStatistics(RequestInfo infro)
{
	unsigned int status = (int)StatisticsStatus::STATISTICS_SUCCESS;
	nlohmann::json json = m_handlerFactory->getStatisticsManager().getStatistics(m_user.getUsername());
	if (json.is_null())
		status = (int)StatisticsStatus::STATISTICS_ERROR;
	GetStatisticsResponse statistics{ status, json };
	Buffer buffer = JsonResponsePacketSerializer::serializeResponse(statistics);
	return RequestResult{ buffer, NULL };
}

// this signout function gets a RequestInfo and return RequestResult
RequestResult MenuRequestHandler::signout(RequestInfo infro)
{
	LogoutResponse logout{ m_handlerFactory->getLoginManager().logout(m_user.getUsername()) };
	Buffer buffer = JsonResponsePacketSerializer::serializeResponse(logout);

	if (logout.status == (int)LogoutStatus::LOGOUT_SUCCESS)
	{
		return RequestResult{ buffer, m_handlerFactory->createLoginRequestHandler() };
	}
	return RequestResult{ buffer, NULL };
}

// this getRooms function gets a RequestInfo and return RequestResult
RequestResult MenuRequestHandler::getRooms(RequestInfo infro)
{
	nlohmann::json json = m_handlerFactory->getRoomManager().getRooms();
	GetRoomsResponse getRooms{ !json["Rooms"].is_null(), json };
	Buffer buffer = JsonResponsePacketSerializer::serializeResponse(getRooms);
	return RequestResult{ buffer, NULL };
}

// this getPlayersInRoom function gets a RequestInfo and return RequestResult
RequestResult MenuRequestHandler::getPlayersInRoom(RequestInfo infro)
{
	GetPlayersInRoomRequest getPlayersRequest = JsonRequestPacketDeserializer::deserializeGetPlayersRequest(infro.buffer);

	GetPlayersInRoomResponse getPlayersResponse{ m_handlerFactory->getRoomManager().getRoom(getPlayersRequest.roomId)->getAllUsers() };
	Buffer buffer = JsonResponsePacketSerializer::serializeResponse(getPlayersResponse);
	return RequestResult{ buffer, NULL };
}

// this joinRoom function gets a RequestInfo and return RequestResult
RequestResult MenuRequestHandler::joinRoom(RequestInfo infro)
{
	JoinRoomRequest joinRoomRequest = JsonRequestPacketDeserializer::deserializeJoinRoomRequest(infro.buffer);
	JoinRoomResponse joinRoom{ (unsigned int)m_handlerFactory->getRoomManager().getRoom(joinRoomRequest.roomId)->addUser(m_user) };
	Buffer buffer = JsonResponsePacketSerializer::serializeResponse(joinRoom);
	return RequestResult{ buffer, NULL };
}

// this createRoom function gets a RequestInfo and return RequestResult
RequestResult MenuRequestHandler::createRoom(RequestInfo infro)
{
	int roomId;
	CreateRoomRequest creatRoomRequest = JsonRequestPacketDeserializer::deserializeCreateRoomRequest(infro.buffer);
	if (creatRoomRequest.roomName.length() < 4 || creatRoomRequest.maxUsers < 1 || creatRoomRequest.maxUsers > 10 || creatRoomRequest.answerTimeout < 1 || creatRoomRequest.answerTimeout > 60 || creatRoomRequest.questionCount < 1 || creatRoomRequest.questionCount > 50)
	{
		roomId = (int)CreateRoom::CreateRoom_ERROR; // if values are invalid
	}
	else
	{
		roomId = m_handlerFactory->getRoomManager().createRoom(creatRoomRequest.roomName, creatRoomRequest.maxUsers, creatRoomRequest.answerTimeout, creatRoomRequest.questionCount, m_user);

	}
	CreateRoomResponse creatRoom{ (roomId != (int)CreateRoom::CreateRoom_ERROR), roomId };
	Buffer buffer = JsonResponsePacketSerializer::serializeResponse(creatRoom);
	return RequestResult{ buffer, NULL };
}
