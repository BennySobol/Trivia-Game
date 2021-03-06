#include "RoomManager.h"

// this function gets a room parameters and create a new room
unsigned int RoomManager::createRoom(std::string name, unsigned int  maxPlayers, unsigned int timePerQuestion, unsigned int  questionCount, LoggedUser& createdBy)
{
	unsigned int id = FIRST_ID;
	for (auto it = m_rooms.cbegin(), end = m_rooms.cend(); it != end && id == it->first; ++it, ++id) {}
	// now id is the next free index
	m_rooms.insert({ id, Room(id, name, maxPlayers, timePerQuestion, questionCount, createdBy.getUsername()) });
	m_rooms[id].addUser(createdBy);
	return id; // secsses
}

// this function delete a given Room by an Id
bool RoomManager::deleteRoom(int id)
{
	if (m_rooms.find(id) != m_rooms.end()) // if room exists
	{
		m_rooms.erase(id); // erase room from rooms 
		return true;
	}
	return false;
}

// this function return a given Room state by an Id
unsigned int RoomManager::getRoomState(int id)
{
	return m_rooms[id].getRoomData().isActive;
}

// this function return a json of all the rooms (name, creator)
nlohmann::json RoomManager::getRooms()
{
	nlohmann::json json = { { "Rooms", {} } };
	for (std::pair<int, Room> room : m_rooms)
	{
		if (!room.second.getRoomData().isActive && room.second.getRoomData().maxPlayers != room.second.getLoggedUser().size()) // if room is joinable
		{
			json["Rooms"].push_back({ {"RoomName", room.second.getRoomData().name }, {"CreatedBy", room.second.getRoomData().createdBy}, {"RoomId", room.second.getRoomData().id} });
		}
	}
	return json;
}

// this function return a given Room by an Id
Room* RoomManager::getRoom(int id)
{
	if (m_rooms.find(id) == m_rooms.end())
	{
		return NULL;
	}
	return &m_rooms[id]; // else return pointer to the room
}
