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
