#include "SqliteDataBase.h"


// Constructor - create the database if not exist, or open it
SqliteDataBase::SqliteDataBase()
{
	int doesFileExist = _access(USERS_SQLITE_DB, 0);
	int res = sqlite3_open(USERS_SQLITE_DB, &db);
	if (res != SQLITE_OK) {
		db = nullptr;
		throw  std::exception(__FUNCTION__ "- Can't create the database");
	}
	else if (doesFileExist == -1)
	{
		const char* usersTBL = "\
			CREATE TABLE IF NOT EXISTS USERS(\
				ID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,\
				USER_NAME TEXT NOT NULL UNIQUE,\
				PASSWORD TEXT NOT NULL,\
				EMAIL TEXT NOT NULL UNIQUE,\
            	PHONE TEXT,\
            	ADDRESS TEXT,\
         	    BIRTH_DATE TEXT\
			);";

		res = sqlite3_exec(db, usersTBL, nullptr, nullptr, nullptr);
		if (res != SQLITE_OK) {
			db = nullptr;
			throw  std::exception(__FUNCTION__ "- Can't create usersTBL");
		}
	}
}

// Destructor - close the database
SqliteDataBase::~SqliteDataBase()
{
	// close the database
	sqlite3_close(db);
	db = nullptr;
}

// this function checks if a user exist in the database
bool SqliteDataBase::doesUserExist(std::string userName)
{
	std::string sqliteCode = "SELECT ID FROM USERS WHERE USER_NAME = " + userName + ";";
	char** errMessage = nullptr;
	std::string id = "";
	sqlite3_exec(db, sqliteCode.c_str(), getRecordId, &id, errMessage);
	return id != "";
}

// this function checks if a given user has the corect password
bool SqliteDataBase::doesPasswordMatch(std::string userName, std::string password) // uml 1 argument
{
	std::string sqliteCode = "SELECT ID FROM USERS WHERE USER_NAME = '" + userName + "' AND PASSWORD = '" + password + "';";
	char** errMessage = nullptr;
	std::string id = "";
	int x= sqlite3_exec(db, sqliteCode.c_str(), getRecordId, &id, errMessage);
	return id != "";
}

// this function trys to add new user to the database
bool SqliteDataBase::addNewUser(std::string userName, std::string password, std::string email, std::string phone, std::string address, std::string birthDate)
{
	char* zErrMsg;
	std::string insertRecords = "INSERT INTO USERS (USER_NAME, PASSWORD, EMAIL, PHONE, ADDRESS, BIRTH_DATE) VALUES ('" + userName + "', '" + password + "', '" + email + "', '" + phone + "', '" + address + "', '" + birthDate + "')";
	int res = sqlite3_exec(db, insertRecords.c_str(), nullptr, nullptr, &zErrMsg);
	if (res != SQLITE_OK) // UNIQUE constraint failed
	{
		return false;
	}
	return true;
}

// this is a callback function that return a the first record id
int SqliteDataBase::getRecordId(void* data, int argc, char** argv, char** azColName)
{
	std::string& dateReference = *static_cast<std::string*>(data);

	// use 'dateReference' which is a reference to 'data'
	if (argv[0] != nullptr)
	{
		dateReference = argv[0];
	}

	// returns SQLITE_ABORT to terminate the callbacks
	return SQLITE_ABORT;
}
