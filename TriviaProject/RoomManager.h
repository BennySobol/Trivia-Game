#pragma once
#include "Room.h"
#include <map>

#define FIRST_ID 1

class RoomManager
{
private:
	std::map<int, Room*> m_rooms;
public:
	RoomManager() = default;
	unsigned int createRoom(std::string name, unsigned int  maxPlayers, unsigned int timePerQuestion, unsigned int  questionCount, LoggedUser& createdBy);
	void deleteRoom(int ID);
	unsigned int getRoomState(int ID);
	nlohmann::json getRooms();
	Room* getRoom(int ID);
};
