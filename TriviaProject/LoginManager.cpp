#include "LoginManager.h"


// LoginManager Constructor
LoginManager::LoginManager() : m_database(new SqliteDataBase()) {}

// LoginManager Distructor
LoginManager::~LoginManager() { delete m_database; }

// login function, return true on success and false otherwise
int LoginManager::signup(std::string userName, std::string password, std::string email, std::string phone, std::string address, std::string birthDate)
{
	int status;

	if (!UserDataValidation::isUsernameValid(userName))
	{
		return 2;
	}
	else if (!UserDataValidation::isPasswordValid(password))
	{
		return 3;
	}
	else if (!UserDataValidation::isEmailValid(email))
	{
		return 4;
	}
	else if (phone != "" && !UserDataValidation::isPhoneValid(phone))
	{
		return 5;
	}
	else if (address != "" && !UserDataValidation::isAddressValid(address))
	{
		return 6;
	}
	else if (birthDate != "" && !UserDataValidation::isBirthDateValid(birthDate))
	{
		return 7;
	}

	if (!m_database->addNewUser(userName, password, email, phone, address, birthDate)) // if userName or email already exist
	{
		return 0;
	}
	return 1;
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
