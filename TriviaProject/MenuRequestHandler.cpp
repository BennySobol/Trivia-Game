#include "MenuRequestHandler.h"

// MenuRequestHandler Constructor
MenuRequestHandler::MenuRequestHandler(std::string username) : m_handlerFactory(RequestHandlerFactory::getInstance()), m_user(username){}

// this function checks if a request is relevant
bool MenuRequestHandler::isRequestRelevant(RequestInfo info)
{
	return info.id == (int)MessageCode::STATISTICS || info.id == (int)MessageCode::LOGOUT || info.id == (int)MessageCode::CREATE_ROOM || info.id == (int)MessageCode::GET_PLAYERS_IN_ROOM || info.id == (int)MessageCode::GET_ROOMS || info.id == (int)MessageCode::JOIN_ROOM;
}

// this function handles a request
RequestResult MenuRequestHandler::handleRequest(RequestInfo info)
{
	switch (info.id)
	{
	case (int)MessageCode::STATISTICS:
		return getStatistics(info);

	case (int)MessageCode::LOGOUT:
		return signout(info);

	case (int)MessageCode::CREATE_ROOM:
		return createRoom(info);

	case (int)MessageCode::GET_PLAYERS_IN_ROOM:
		return getPlayersInRoom(info);

	case (int)MessageCode::GET_ROOMS:
		return getRooms(info);

	case (int)MessageCode::JOIN_ROOM:
		return joinRoom(info);

	default:
		return RequestResult{ JsonResponsePacketSerializer::serializeResponse(ErrorResponse{ "error - not a valid request" }), m_handlerFactory->createMenuRequestHandler(m_user.getUsername()) };
	}
}

// this statistics function gets a RequestInfo and return RequestResult
RequestResult MenuRequestHandler::getStatistics(RequestInfo info)
{
	unsigned int status = SUCCESS_STATUS;
	nlohmann::json json = m_handlerFactory->getStatisticsManager().getStatistics(m_user.getUsername());
	if (json.is_null())
	{
		status = ERROR_STATUS;
	}
	GetStatisticsResponse statistics{ status, json };
	return RequestResult{ JsonResponsePacketSerializer::serializeResponse(statistics), NULL };
}

// this signout function gets a RequestInfo and return RequestResult
RequestResult MenuRequestHandler::signout(RequestInfo info)
{
	LogoutResponse logout{ m_handlerFactory->getLoginManager().logout(m_user.getUsername()) };
	Buffer buffer = JsonResponsePacketSerializer::serializeResponse(logout);
	if (logout.status == SUCCESS_STATUS)
	{
		return RequestResult{ buffer, m_handlerFactory->createLoginRequestHandler() };
	}
	return RequestResult{ buffer, NULL };
}

// this getRooms function gets a RequestInfo and return RequestResult
RequestResult MenuRequestHandler::getRooms(RequestInfo info)
{
	nlohmann::json json = m_handlerFactory->getRoomManager().getRooms();
	GetRoomsResponse getRooms{ !json["Rooms"].is_null(), json };
	return RequestResult{ JsonResponsePacketSerializer::serializeResponse(getRooms), NULL };
}

// this getPlayersInRoom function gets a RequestInfo and return RequestResult
RequestResult MenuRequestHandler::getPlayersInRoom(RequestInfo info)
{
	GetPlayersInRoomRequest getPlayersRequest = JsonRequestPacketDeserializer::deserializeGetPlayersRequest(info.buffer);
	GetPlayersInRoomResponse getPlayersResponse{ m_handlerFactory->getRoomManager().getRoom(getPlayersRequest.roomId)->getAllUsers() };
	return RequestResult{ JsonResponsePacketSerializer::serializeResponse(getPlayersResponse), NULL };
}

// this joinRoom function gets a RequestInfo and return RequestResult
RequestResult MenuRequestHandler::joinRoom(RequestInfo info)
{
	JoinRoomRequest joinRoomRequest = JsonRequestPacketDeserializer::deserializeJoinRoomRequest(info.buffer);
	JoinRoomResponse joinRoom{ (unsigned int)m_handlerFactory->getRoomManager().getRoom(joinRoomRequest.roomId)->addUser(m_user) };
	Buffer buffer = JsonResponsePacketSerializer::serializeResponse(joinRoom);
	if (joinRoom.status == ERROR_STATUS)
	{
		return RequestResult{ buffer, NULL };
	}
	return RequestResult{ buffer, m_handlerFactory->createRoomMemberRequestHandler(joinRoomRequest.roomId, m_user.getUsername()) };
}

// this createRoom function gets a RequestInfo and return RequestResult
RequestResult MenuRequestHandler::createRoom(RequestInfo info)
{
	int roomId;
	CreateRoomRequest creatRoomRequest = JsonRequestPacketDeserializer::deserializeCreateRoomRequest(info.buffer);
	if (creatRoomRequest.roomName.length() < MIN_ROOM_NAME_LENGTH || creatRoomRequest.maxUsers < 1 || creatRoomRequest.maxUsers > MAX_PLAYERS_IN_GAME || creatRoomRequest.answerTimeout < 1 || creatRoomRequest.answerTimeout > MAX_ANSWER_TIMEOUT || creatRoomRequest.questionCount < 1 || creatRoomRequest.questionCount > MAX_QUESTION_COUNT)
	{ // if values are invalid
		roomId = ERROR_STATUS;
	}
	else
	{ 
		roomId = m_handlerFactory->getRoomManager().createRoom(creatRoomRequest.roomName, creatRoomRequest.maxUsers, creatRoomRequest.answerTimeout, creatRoomRequest.questionCount, m_user);
	}
	CreateRoomResponse creatRoom{ (roomId != ERROR_STATUS) };
	Buffer buffer = JsonResponsePacketSerializer::serializeResponse(creatRoom);
	if (creatRoom.status == ERROR_STATUS)
	{
		return RequestResult{ buffer, NULL };
	}
	return RequestResult{ buffer, m_handlerFactory->createRoomAdminRequestHandler(roomId, m_user.getUsername()) };
}
