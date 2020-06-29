#pragma once
#include "Question.h"
#include "LoggedUser.h"
#include "Room.h"
#include <sstream>
#include <iomanip>

typedef struct GameData
{
	unsigned int currentQuestionIndex;
	unsigned int correctAnswerCount;
	unsigned int wrongAnswerCount;
	double averangeAnswerTime;
	time_t startTimer;
	bool hasFinished;
	bool hasTryToDeleteGame;
} GameData;

class Game
{
private:
	int m_timePerQuestion;
	std::vector<Question> m_questions;
	std::map<std::string, GameData> m_players;
public:
	Game(Room room, std::list<nlohmann::json> questions);
	Question getQuestionForUser(LoggedUser user);
    bool submitAnswer(LoggedUser user, unsigned int answerId);
    bool removePlayer(LoggedUser user);
	nlohmann::json getGameResults();
	GameData& getUserData(std::string username);
	void setTryToDeleteGame(std::string username);
	bool isGameCanBeDeleted();
};
