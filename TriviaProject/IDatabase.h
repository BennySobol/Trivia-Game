#pragma once
#include "json.hpp"
#include <iostream>
#include <list>

class IDatabase
{
public:
	IDatabase() = default;
	virtual bool doesUserExist(std::string) = 0;
	virtual bool doesPasswordMatch(std::string, std::string) = 0;
	virtual int addNewUser(std::string, std::string, std::string, std::string, std::string, std::string) = 0;
	virtual std::list<nlohmann::json> getQuestions(int) = 0;
	virtual double getPlayerAverageAnswerTime(std::string) = 0;
	virtual int getNumOfCorrectAnswers(std::string) = 0;
	virtual int getNumOfWrongAnswers(std::string) = 0;
	virtual int getNumOfPlayerGames(std::string) = 0;
	virtual std::list<nlohmann::json> getTheBestPlayers() = 0;
	virtual void addGameToStatistics(std::string username, unsigned int correctAnswerCount, unsigned int wrongAnswerCount, double averangeAnswerTime) = 0;
};
