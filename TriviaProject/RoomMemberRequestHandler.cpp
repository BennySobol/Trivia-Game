#include "RoomMemberRequestHandler.h"


// RoomMemberRequestHandler Constructor
RoomMemberRequestHandler::RoomMemberRequestHandler(unsigned int roomId, std::string username) : m_handlerFactory(RequestHandlerFactory::getInstance()), m_user(username), m_roomId(roomId) {}

// this function checks if a request is relevant
bool RoomMemberRequestHandler::isRequestRelevant(RequestInfo infro)
{
	return infro.id == (int)MessageCode::LEAVE_ROOM || infro.id == (int)MessageCode::GET_ROOM_STATE;
}

// this function handles a request
RequestResult RoomMemberRequestHandler::handleRequest(RequestInfo infro)
{
	switch (infro.id)
	{
	case (int)MessageCode::LEAVE_ROOM:
		return leaveRoom(infro);

	case (int)MessageCode::GET_ROOM_STATE:
		return getRoomState(infro);

	default:
		return RequestResult{ JsonResponsePacketSerializer::serializeResponse(ErrorResponse{ "error - not a valid request" }), m_handlerFactory->createMenuRequestHandler(m_user.getUsername()) };
	}
}

// this leaveRoom function gets a RequestInfo and return RequestResult
RequestResult RoomMemberRequestHandler::leaveRoom(RequestInfo)
{
	StartGameResponse leaveRoom;
	Room* room = m_handlerFactory->getRoomManager().getRoom(m_roomId);
	if (room == NULL) // if room was closed
	{
		leaveRoom.status = (int)LeaveRoom::LEAVE_ROOM_SUCCESS;
	}
	else
	{  // leave the room
		leaveRoom.status = m_handlerFactory->getRoomManager().getRoom(m_roomId)->removeUser(m_user);
	}
	Buffer buffer = JsonResponsePacketSerializer::serializeResponse(leaveRoom);
	return RequestResult{ buffer, m_handlerFactory->createMenuRequestHandler(m_user.getUsername()) };
}

// this getRoomState function gets a RequestInfo and return RequestResult
RequestResult RoomMemberRequestHandler::getRoomState(RequestInfo)
{
	Room* room = m_handlerFactory->getRoomManager().getRoom(m_roomId);
	if (room == NULL) // if room was closed
	{ // send error to the cient
		GetRoomStateResponse getRoomState{ (int)GetRoomState::ROOM_IS_CLOSED_ERROR, (int)GetRoomState::ROOM_IS_CLOSED_ERROR, nlohmann::json{ { "PlayersInRoom", {} } } ,(int)GetRoomState::ROOM_IS_CLOSED_ERROR , (int)GetRoomState::ROOM_IS_CLOSED_ERROR };
		return RequestResult{ JsonResponsePacketSerializer::serializeResponse(getRoomState), NULL };
	} // else get room state
	RoomData roomData = m_handlerFactory->getRoomManager().getRoom(m_roomId)->getRoomData();
	GetRoomStateResponse getRoomState{ (int)GetRoomState::GET_ROOM_SUCCESS , roomData.isActive, m_handlerFactory->getRoomManager().getRoom(m_roomId)->getAllUsers(), roomData.questionCount, roomData.timePerQuestion };
	return RequestResult{ JsonResponsePacketSerializer::serializeResponse(getRoomState), NULL };
}