#include "LoginManager.h"


// LoginManager Constructor
LoginManager::LoginManager() : m_database(new SqliteDataBase()) {}

// LoginManager Distructor
LoginManager::~LoginManager() { delete m_database; }


// login function, return true on success and false otherwise
bool LoginManager::signup(std::string userName, std::string password, std::string email)
{
	// need to be validate //

	if (!m_database->addNewUser(userName, password, email)) // if userName or email already exist
	{
		return false;
	}
	return true;
}

// login function, return true on success and false otherwise
bool LoginManager::login(std::string userName, std::string password)
{
	if (!isLogin(userName) && m_database->doesPasswordMatch(userName, password)) // if the user login is valid
	{
		m_loggedUsers.push_back(LoggedUser(userName)); // add user
		return true;
	}
	return false;
}

// logout function, return true on success and false otherwise
bool LoginManager::logout(std::string userName)
{
	auto it = find_if(m_loggedUsers.begin(), m_loggedUsers.end(), [&userName](LoggedUser& obj) { return obj.getUsername() == userName; });
	if (it != m_loggedUsers.end()) // if found element
	{
		m_loggedUsers.erase(it);
		return true;
	}
	return false; // user not exist
}

// isLogin function, return true if a given user is loged in and false otherwise
bool LoginManager::isLogin(std::string userName)
{
	auto it = find_if(m_loggedUsers.begin(), m_loggedUsers.end(), [&userName](LoggedUser& obj) {return obj.getUsername() == userName; });
	if (it != m_loggedUsers.end()) // if found element
	{
		return true;
	}
	return false;
}