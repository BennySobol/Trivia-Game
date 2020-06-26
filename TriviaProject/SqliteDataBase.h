#pragma once
#include "IDatabase.h"
#include "CodeProtocol.h"
#include "sqlite3.h"
#include "base64.h"
#include <io.h>
#include <sstream>
#include <iomanip>

#pragma comment(lib, "urlmon.lib")

#define USERS_SQLITE_DB "TriviaDatabase.sqlite"
#define FILE_DOES_NOT_EXIST -1
#define BUFFER_SIZE 1024

class SqliteDataBase : public IDatabase
{
private:
    sqlite3* db;
	SqliteDataBase();
	~SqliteDataBase();
public:
	static SqliteDataBase* getInstance();
	bool doesUserExist(std::string);
	bool doesPasswordMatch(std::string, std::string);
	int addNewUser(std::string, std::string, std::string, std::string, std::string, std::string);
	std::list<nlohmann::json> getQuestions(int);
	double getPlayerAverageAnswerTime(std::string);
	int getNumOfCorrectAnswers(std::string);
	int getNumOfWrongAnswers(std::string);
	int getNumOfPlayerGames(std::string);
	std::list<nlohmann::json> getTheBestPlayers();
	void addGameToStatistics(std::string, unsigned int, unsigned int, double);
	std::string getUserId(std::string);
	static int getRecordFirstValue(void*, int, char**, char**);
	static int getQuestionsList(void*, int, char**, char**);
	static int getBestPlayersList(void*, int, char**, char**);
};
