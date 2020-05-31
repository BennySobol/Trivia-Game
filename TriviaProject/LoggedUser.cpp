#include "LoggedUser.h"

// LoginManager Constructor
LoggedUser::LoggedUser(std::string username)
{
	m_username = username;
}

// get the user name
std::string LoggedUser::getUsername()
{
	return m_username;
}

// get is user in a room
bool LoggedUser::isInRoom()
{
	return m_isInRoom;
}

// set if a user in a room
void LoggedUser::setIsInRoom(bool isInRoom)
{
	m_isInRoom = isInRoom;
}
