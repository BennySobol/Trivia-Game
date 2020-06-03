#pragma once
#include <iostream>

class LoggedUser
{
private:
	bool m_isInRoom;
    std::string m_username;
public:
	LoggedUser(std::string username);
	std::string getUsername();
};

