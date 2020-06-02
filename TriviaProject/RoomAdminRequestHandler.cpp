#include "RoomAdminRequestHandler.h"

// RoomAdminRequestHandler Constructor
RoomAdminRequestHandler::RoomAdminRequestHandler(unsigned int roomId, std::string username) : m_handlerFactory(RequestHandlerFactory::getInstance()) , m_user(username), m_roomId(roomId) {}

// this function checks if a request is relevant
bool RoomAdminRequestHandler::isRequestRelevant(RequestInfo infro)
{
	return infro.id == (int)MessageCode::START_GAME || infro.id == (int)MessageCode::CLOSE_ROOM || infro.id == (int)MessageCode::GET_ROOM_STATE;
}

// this function handles a request
RequestResult RoomAdminRequestHandler::handleRequest(RequestInfo infro)
{
	switch (infro.id)
	{
	case (int)MessageCode::CLOSE_ROOM:
		return closeRoom(infro);

	case (int)MessageCode::START_GAME:
		return startGame(infro);

	case (int)MessageCode::GET_ROOM_STATE:
		return getRoomState(infro);

	default:
		return RequestResult{ JsonResponsePacketSerializer::serializeResponse(ErrorResponse{ "error - not a valid request" }), m_handlerFactory->createMenuRequestHandler(m_user.getUsername()) };
	}
}

// this closeRoom function gets a RequestInfo and return RequestResult
RequestResult RoomAdminRequestHandler::closeRoom(RequestInfo infro)
{

	CloseRoomResponse closeRoom{ (unsigned int)m_handlerFactory->getRoomManager().deleteRoom(m_roomId) };
	Buffer buffer = JsonResponsePacketSerializer::serializeResponse(closeRoom);
	return RequestResult{ buffer, m_handlerFactory->createMenuRequestHandler(m_user.getUsername()) };
}

// this startGame function gets a RequestInfo and return RequestResult
RequestResult RoomAdminRequestHandler::startGame(RequestInfo infro)
{
	m_handlerFactory->getRoomManager().getRoom(m_roomId)->getRoomData().isActive = true;
	StartGameResponse startGame{ true };
	Buffer buffer = JsonResponsePacketSerializer::serializeResponse(startGame);
	return RequestResult{ buffer, NULL }; // need to be done
}

// this getRoomState function gets a RequestInfo and return RequestResult
RequestResult RoomAdminRequestHandler::getRoomState(RequestInfo infro)
{
	RoomData roomData = m_handlerFactory->getRoomManager().getRoom(m_roomId)->getRoomData();
	GetRoomStateResponse getRoomState{ true, roomData.isActive, m_handlerFactory->getRoomManager().getRoom(m_roomId)->getAllUsers(), roomData.questionCount, roomData.timePerQuestion };
	Buffer buffer = JsonResponsePacketSerializer::serializeResponse(getRoomState);
	return RequestResult{ buffer, NULL };
}