#pragma once
#include "IDatabase.h"
#include "json.hpp"
#include <fstream>
#include "sqlite3.h"
#include "iostream"
#include <io.h>

#define USERS_SQLITE_DB "TriviaDatabase.sqlite"

class SqliteDataBase : public IDatabase
{
private:
    sqlite3* db;
public:
	SqliteDataBase();
	~SqliteDataBase();
	bool doesUserExist(std::string);
	bool doesPasswordMatch(std::string, std::string);
	bool addNewUser(std::string, std::string, std::string);
	static int getRecordId(void* data, int argc, char** argv, char** azColName);
};
