#include "RoomManager.h"
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

Room::Room(LoggedUser creator, unsigned int ID)
{
	this->m_metadata.id = ID;
	m_users.push_back(creator);
}

RoomData Room::getRoomData()
{
	return this->m_metadata;
}

void Room::addUser(LoggedUser user)
{
	m_users.push_back(user);
}

void Room::removeUser(LoggedUser user)
{
	std::vector<LoggedUser>::iterator position = std::find(m_users.begin(), m_users.end(), user);
	if (position != m_users.end())
		m_users.erase(position);
	else
	{
		std::cout << "User doesn't exist";
	}
}

std::vector<std::string> Room::getAllUsers()
{
	std::vector<std::string> allUsers;
	for (LoggedUser i : m_users)
	{
		allUsers.push_back(i.getUsername());
	}
	return allUsers;
}

void RoomManager::createRoom(LoggedUser user)
{
	Room room(user, _roomNumber);
	m_rooms.insert(std::pair<unsigned int, Room>(_roomNumber, room));
	_roomNumber++;
}

void RoomManager::deleteRoom(int ID)
{
	m_rooms.erase(ID);
}

unsigned int RoomManager::getRoomState(unsigned int ID)
{
	return m_rooms[ID].getRoomData().isActive;
}

std::vector<RoomData>  RoomManager::getRooms()
{
	std::vector<RoomData> Rooms;
	for (std::pair<unsigned int, Room> i : m_rooms)
	{
		Rooms.push_back(i.second.getRoomData());
	}
	return Rooms;
}