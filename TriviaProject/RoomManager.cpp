#include "RoomManager.h"

// this function gets a room parameters and create a new room
unsigned int RoomManager::createRoom(std::string name, unsigned int  maxPlayers, unsigned int timePerQuestion, unsigned int  questionCount, LoggedUser& createdBy)
{
	if (createdBy.isInRoom()) // if user is already inside a room
	{
		return (int)CreateRoom::CreateRoom_ERROR;
	}
	unsigned int id = FIRST_ID;
	for (auto it = m_rooms.cbegin(), end = m_rooms.cend(); it != end && id == it->first; ++it, ++id) {}
	// now id is the next free index
	m_rooms.insert(std::make_pair(id, new Room(id, name, maxPlayers, timePerQuestion, questionCount, createdBy.getUsername())));
	m_rooms[id]->addUser(createdBy);
	return id; // secsses
}

// this function delete a given Room by an Id
void RoomManager::deleteRoom(int ID)
{
	m_rooms.erase(ID);   // erase room from rooms 
}

// this function return a given Room state by an Id
unsigned int RoomManager::getRoomState(int ID)
{
	return m_rooms[ID]->getRoomData().isActive;
}

// this function return a json off all the rooms (name, creator)
nlohmann::json RoomManager::getRooms()
{
	nlohmann::json json = { { "Rooms", {} } };
	for (std::pair<int, Room*> room : m_rooms)
	{
		json["Rooms"].push_back({ {"RoomName", room.second->getRoomData().name }, {"CreatedBy", room.second->getRoomData().createdBy}, {"RoomId", room.second->getRoomData().id} });
	}
	return json;
}

// this function return a given Room by an Id
Room* RoomManager::getRoom(int ID)
{
	return m_rooms[ID];
}
