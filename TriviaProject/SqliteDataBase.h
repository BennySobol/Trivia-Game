#pragma once
#include "IDatabase.h"
#include "json.hpp"
#include <fstream>
#include "sqlite3.h"
#include "iostream"
#include <io.h>
#include <sstream>

#pragma comment(lib, "urlmon.lib")

#define USERS_SQLITE_DB "TriviaDatabase.sqlite"
#define FILE_DOES_NOT_EXIST -1

class SqliteDataBase : public IDatabase
{
private:
    sqlite3* db;
public:
	SqliteDataBase();
	~SqliteDataBase();
	bool doesUserExist(std::string);
	bool doesPasswordMatch(std::string, std::string);
	bool addNewUser(std::string, std::string, std::string, std::string, std::string, std::string);
	static int getRecordId(void* data, int argc, char** argv, char** azColName);
	static int getQuestion(void* data, int argc, char** argv, char** azColName);
	nlohmann::json getRandomQuestion();
};
