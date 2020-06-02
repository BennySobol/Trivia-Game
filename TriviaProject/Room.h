#pragma once
#include <vector>
#include <iostream>
#include "CodeProtocol.h"
#include "LoggedUser.h"
#include "json.hpp"


typedef struct RoomData
{
	unsigned int id;
	std::string name;
	unsigned int  maxPlayers;
	unsigned int timePerQuestion;
	bool isActive;
	unsigned int questionCount;
	std::string createdBy;
} RoomData;

class Room
{
private:
	RoomData m_metadata;
	std::vector<LoggedUser> m_users;
public:
	Room(unsigned int id, std::string name, unsigned int  maxPlayers, unsigned int timePerQuestion, unsigned int isActive, std::string createdBy);
	bool addUser(LoggedUser&);
	bool removeUser(LoggedUser);
	nlohmann::json getAllUsers();
	RoomData& getRoomData();
};

