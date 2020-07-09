#pragma once
#include <iostream>

class LoggedUser
{
private:
    std::string m_username;
public:
	LoggedUser(std::string username);
	std::string getUsername();
};

