#pragma once
#include "LoggedUser.h"
#include "SqliteDataBase.h"
#include <vector>

class LoginManager
{
private:
	IDatabase* m_database;
	std::vector<LoggedUser> m_loggedUsers;
public:
	LoginManager();
	~LoginManager();
	bool signup(std::string userName, std::string password, std::string email);
	bool login(std::string userName, std::string password);
	bool logout(std::string);
	bool isLogin(std::string userName);
};



