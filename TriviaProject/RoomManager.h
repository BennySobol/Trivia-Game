#pragma once
#include "LoggedUser.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>
typedef struct RoomData
{
	unsigned int id;
	std::string name;
	std::string maxPlayers;
	unsigned int timePerQuestion;
	unsigned int isActive;
}RoomData;

class Room
{
public:
	Room(LoggedUser, unsigned int);
	void addUser(LoggedUser);
	void removeUser(LoggedUser);
	std::vector<std::string> getAllUsers();
	RoomData getRoomData();
private:
	RoomData m_metadata;
	std::vector<LoggedUser> m_users;
};

class RoomManager
{
	unsigned int _roomNumber = 0;
	std::map<unsigned int, Room> m_rooms;
public:
	void createRoom(LoggedUser);
	void deleteRoom(int ID);
	unsigned int getRoomState(unsigned int ID);
	std::vector<RoomData>getRooms();
};