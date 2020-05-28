#include "LoginManager.h"

std::vector<LoggedUser> LoginManager::m_loggedUsers;

// LoginManager Constructor
LoginManager::LoginManager() : m_database(new SqliteDataBase()) {}

// LoginManager Distructor
LoginManager::~LoginManager() { delete m_database; }

// login function, return true on success and false otherwise
int LoginManager::signup(std::string userName, std::string password, std::string email, std::string phone, std::string address, std::string birthDate)
{
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
	if (phone != "" && !UserDataValidation::isPhoneValid(phone))
	{
		return (int)SignupStatus::INVALID_PHONE;
	}
	if (address != "" && !UserDataValidation::isAddressValid(address))
	{
		return (int)SignupStatus::INVALID_ADDRESS;
	}
	if (birthDate != "" && !UserDataValidation::isBirthDateValid(birthDate))
	{
		return (int)SignupStatus::INVALID_BIRTHDATE;
	}
	if (!m_database->addNewUser(userName, password, email, phone, address, birthDate)) // if userName or email already exist
	{
		return (int)SignupStatus::ALREADY_EXIST_ERROR;
	}
	return (int)SignupStatus::SIGNUP_SUCCESS;
}

// login function, return true on success and false otherwise
int LoginManager::login(std::string userName, std::string password)
{
	if (!isLogin(userName) && m_database->doesPasswordMatch(userName, password)) // if the user login is valid
	{
		m_loggedUsers.push_back(LoggedUser(userName)); // add user
		return (int)LoginStatus::LOGIN_SUCCESS;
	}
	return (int)LoginStatus::LOGIN_ERROR;
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
