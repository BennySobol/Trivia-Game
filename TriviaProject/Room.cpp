#include "Room.h"

// Room Constructor
Room::Room(unsigned int id, std::string name, unsigned int  maxPlayers, unsigned int timePerQuestion, unsigned int questionCount, std::string createdBy) : m_metadata{ id, name, maxPlayers, timePerQuestion, false, questionCount, createdBy } {}

// this function adds a given user from a room
bool Room::addUser(LoggedUser& user)
{
	if (m_metadata.maxPlayers != m_users.size()) // if there is maximum players
	{
		m_users.push_back(user);
		return true;
	}
	return false;
}

// this function removes a given user from a room
bool Room::removeUser(LoggedUser user)
{
	std::vector<LoggedUser>::iterator position = std::find_if(m_users.begin(), m_users.end(), [&user](LoggedUser& obj) {return obj.getUsername() == user.getUsername(); });
	if (position != m_users.end()) // if found element
	{
		m_users.erase(position);
		return true;
	}
	return false;
}

// this function returns a json of all the users name in the room
nlohmann::json Room::getAllUsers()
{
	nlohmann::json json = { { "PlayersInRoom", {} } };
	for (LoggedUser player : m_users)
	{
		json["PlayersInRoom"].push_back(nlohmann::json{ { "PlayerName", player.getUsername() } });
	}
	return json;
}

// this function return the room data
RoomData& Room::getRoomData()
{
	return m_metadata;
}