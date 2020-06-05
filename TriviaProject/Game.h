#pragma once
#include "Question.h"
#include "LoggedUser.h"
#include "Room.h"


typedef struct GameData
{
	int currentQuestionIndex;
	unsigned int correctAnswerCount;
	unsigned int wrongAnswerCount;
	unsigned int averangeAnswerTime;
} GameData;

class Game
{
private:
	std::vector<Question> m_questions;
	std::map<std::string, GameData> m_players;
public:
	Game() = default; // fix
	Game(Room room, std::list<nlohmann::json> questions);
	Question getQuestionForUser(LoggedUser user);
    bool submitAnswer(LoggedUser user, unsigned int answerId, unsigned int averangeTime);
    bool removePlayer(LoggedUser user);
};

