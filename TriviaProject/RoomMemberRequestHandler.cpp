#include "RoomMemberRequestHandler.h"

// RoomMemberRequestHandler Constructor
RoomMemberRequestHandler::RoomMemberRequestHandler(unsigned int roomId, std::string username) : m_handlerFactory(RequestHandlerFactory::getInstance()), m_user(username), m_roomId(roomId) {}

// this function checks if a request is relevant
bool RoomMemberRequestHandler::isRequestRelevant(RequestInfo info)
{
	return info.id == (int)MessageCode::LEAVE_ROOM || info.id == (int)MessageCode::GET_ROOM_STATE;
}

// this function handles a request
RequestResult RoomMemberRequestHandler::handleRequest(RequestInfo info)
{
	switch (info.id)
	{
	case (int)MessageCode::LEAVE_ROOM:
		return leaveRoom(info);

	case (int)MessageCode::GET_ROOM_STATE:
		return getRoomState(info);

	default:
		return RequestResult{ JsonResponsePacketSerializer::serializeResponse(ErrorResponse{ "error - not a valid request" }), NULL };
	}
}

// this leaveRoom function gets a RequestInfo and return RequestResult
RequestResult RoomMemberRequestHandler::leaveRoom(RequestInfo info)
{
	StartGameResponse leaveRoom;
	Room* room = m_handlerFactory->getRoomManager().getRoom(m_roomId);
	if (room == NULL) // if room was closed
	{
		leaveRoom.status = SUCCESS_STATUS;
	}
	else
	{  // leave the room
		leaveRoom.status = room->removeUser(m_user);
	}
	return RequestResult{ JsonResponsePacketSerializer::serializeResponse(leaveRoom), m_handlerFactory->createMenuRequestHandler(m_user.getUsername()) };
}

// this getRoomState function gets a RequestInfo and return RequestResult
RequestResult RoomMemberRequestHandler::getRoomState(RequestInfo info)
{
	Room* room = m_handlerFactory->getRoomManager().getRoom(m_roomId);
	if (room == NULL) // if room was closed
	{ // send an error to the client
		GetRoomStateResponse getRoomState{ ERROR_STATUS, ERROR_STATUS, nlohmann::json{ { "PlayersInRoom", {} } } ,ERROR_STATUS , ERROR_STATUS };
		return RequestResult{ JsonResponsePacketSerializer::serializeResponse(getRoomState), NULL };
	} // else get room state
	RoomData roomData = room->getRoomData();
	GetRoomStateResponse getRoomState{ SUCCESS_STATUS , roomData.isActive, room->getAllUsers(), roomData.questionCount, roomData.timePerQuestion };
	if (getRoomState.hasGameBegun) // if game has begun
	{ // create new GameRequestHandler
		return RequestResult{ JsonResponsePacketSerializer::serializeResponse(getRoomState), m_handlerFactory->createGameRequestHandler(m_user.getUsername(), m_handlerFactory->getGameManager().getGame(m_roomId)) };
	} // else send the game state
	return RequestResult{ JsonResponsePacketSerializer::serializeResponse(getRoomState), NULL };
}