#include "LoginManager.h"


// LoginManager Constructor
LoginManager::LoginManager() : m_database(SqliteDataBase::getInstance()) {}

// signup function, return true on success and false otherwise
int LoginManager::signup(std::string userName, std::string password, std::string email, std::string phone, std::string address, std::string birthDate)
{
	// if all signup ditails are valid
	if (!UserDataValidation::isUsernameValid(userName))
	{
		return (int)SignupStatus::INVALID_USERNAME;
	}
	if (!UserDataValidation::isPasswordValid(password))
	{
		return (int)SignupStatus::INVALID_PASSWORD;
	}
    if (!UserDataValidation::isEmailValid(email))
	{
		return (int)SignupStatus::INVALID_EMAIL;
	}
	if (address != "" && !UserDataValidation::isAddressValid(address))
	{
		return (int)SignupStatus::INVALID_ADDRESS;
	}
	if (phone != "" && !UserDataValidation::isPhoneValid(phone))
	{
		return (int)SignupStatus::INVALID_PHONE;
	}
	if (birthDate != "" && !UserDataValidation::isBirthDateValid(birthDate))
	{
		return (int)SignupStatus::INVALID_BIRTHDATE;
	}
	return m_database->addNewUser(userName, password, email, phone, address, birthDate);
}

// login function, return true on success and false otherwise
int LoginManager::login(std::string userName, std::string password)
{
	if (findUser(userName) != m_loggedUsers.end())
	{
		return (int)LoginStatus::USER_ALREADY_CONNECTED_ERROR;
	}
	if (m_database->doesPasswordMatch(userName, password)) // if the user login is valid
	{
		m_loggedUsers.push_back(LoggedUser(userName)); // add the user
		return (int)LoginStatus::LOGIN_SUCCESS;
	}
	return (int)LoginStatus::LOGIN_ERROR;
}

// logout function, return true on success and false otherwise
bool LoginManager::logout(std::string userName)
{
	std::vector<LoggedUser>::iterator it = findUser(userName);
	if (it != m_loggedUsers.end()) // if found element
	{
		m_loggedUsers.erase(it);
		return true;
	}
	return false; // user not exist
}

// findUser function, return a given user iterator
std::vector<LoggedUser>::iterator LoginManager::findUser(std::string userName)
{
	return std::find_if(m_loggedUsers.begin(), m_loggedUsers.end(), [&userName](LoggedUser& obj) {return obj.getUsername() == userName; });
}
