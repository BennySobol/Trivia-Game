#pragma once
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include "json.hpp"

class Question
{
private:
	int m_correctAnswerId;
	nlohmann::json m_possibleAnswersJson;
	nlohmann::json m_question;
public:
	Question(nlohmann::json question);
	std::string getQuestion();
	nlohmann::json getPossibleAnswers();
	int getCorrentAnswerId();
	std::string getDifficulty();
	std::string getCategory();
};

