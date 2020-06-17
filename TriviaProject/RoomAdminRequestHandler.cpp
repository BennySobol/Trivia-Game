#include "RoomAdminRequestHandler.h"

// RoomAdminRequestHandler Constructor
RoomAdminRequestHandler::RoomAdminRequestHandler(unsigned int roomId, std::string username) : m_handlerFactory(RequestHandlerFactory::getInstance()) , m_user(username), m_roomId(roomId) {}

// this function checks if a request is relevant
bool RoomAdminRequestHandler::isRequestRelevant(RequestInfo info)
{
	return info.id == (int)MessageCode::START_GAME || info.id == (int)MessageCode::CLOSE_ROOM || info.id == (int)MessageCode::GET_ROOM_STATE;
}

// this function handles a request
RequestResult RoomAdminRequestHandler::handleRequest(RequestInfo info)
{
	switch (info.id)
	{
	case (int)MessageCode::CLOSE_ROOM:
		return closeRoom(info);

	case (int)MessageCode::START_GAME:
		return startGame(info);

	case (int)MessageCode::GET_ROOM_STATE:
		return getRoomState(info);

	default:
		return RequestResult{ JsonResponsePacketSerializer::serializeResponse(ErrorResponse{ "error - not a valid request" }), m_handlerFactory->createMenuRequestHandler(m_user.getUsername()) };
	}
}

// this closeRoom function gets a RequestInfo and return RequestResult
RequestResult RoomAdminRequestHandler::closeRoom(RequestInfo info)
{
	CloseRoomResponse closeRoom{ (unsigned int)m_handlerFactory->getRoomManager().deleteRoom(m_roomId) };
	return RequestResult{ JsonResponsePacketSerializer::serializeResponse(closeRoom), m_handlerFactory->createMenuRequestHandler(m_user.getUsername()) };
}

// this startGame function gets a RequestInfo and return RequestResult
RequestResult RoomAdminRequestHandler::startGame(RequestInfo info)
{
	m_handlerFactory->getRoomManager().getRoom(m_roomId)->getRoomData().isActive = true;
	StartGameResponse startGame{ SUCCESS_STATUS };
	m_handlerFactory->getGameManager().createGame(*m_handlerFactory->getRoomManager().getRoom(m_roomId)); // create game
	return RequestResult{ JsonResponsePacketSerializer::serializeResponse(startGame), m_handlerFactory->createGameRequestHandler(m_user.getUsername(), m_handlerFactory->getGameManager().getGame(m_roomId)) };
}

// this getRoomState function gets a RequestInfo and return RequestResult
RequestResult RoomAdminRequestHandler::getRoomState(RequestInfo info)
{
	Room* room = m_handlerFactory->getRoomManager().getRoom(m_roomId);
	if (room == NULL) // if room was closed
	{ // send error to the cient
		GetRoomStateResponse getRoomState{ ERROR_STATUS, ERROR_STATUS, nlohmann::json{ { "PlayersInRoom", {} } } ,ERROR_STATUS , ERROR_STATUS };
		return RequestResult{ JsonResponsePacketSerializer::serializeResponse(getRoomState), NULL };
	} // else get room state
	RoomData roomData = m_handlerFactory->getRoomManager().getRoom(m_roomId)->getRoomData();
	GetRoomStateResponse getRoomState{ SUCCESS_STATUS , roomData.isActive, m_handlerFactory->getRoomManager().getRoom(m_roomId)->getAllUsers(), roomData.questionCount, roomData.timePerQuestion };
	return RequestResult{ JsonResponsePacketSerializer::serializeResponse(getRoomState), NULL };
}