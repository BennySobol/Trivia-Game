#pragma once
#include "IDatabase.h"
#include "sqlite3.h"
#include "iostream"
#include <io.h>
#include <sstream>

#pragma comment(lib, "urlmon.lib")

#define USERS_SQLITE_DB "TriviaDatabase.sqlite"
#define FILE_DOES_NOT_EXIST -1
#define BUFFER_SIZE 1024

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

	std::list<nlohmann::json> getQuestions(int);
	float getPlayerAverageAnswerTime(std::string);
	int getNumOfCorrectAnswers(std::string);
	int getNumOfTotalAnswers(std::string);
	int getNumOfPlayerGames(std::string);
	std::list<nlohmann::json> getTheBestPlayers();
	//void addAnswer(std::string username, float time, bool isCorrect);

	static int getRecordFirstValue(void* data, int argc, char** argv, char** azColName);
	static int getQuestionsList(void* data, int argc, char** argv, char** azColName);
	static int getBestPlayersList(void* data, int argc, char** argv, char** azColName);
};
