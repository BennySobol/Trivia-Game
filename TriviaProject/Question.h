#pragma once
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include "json.hpp"

class Question
{
private:
	unsigned int m_correctAnswerId;
	nlohmann::json m_question;
public:
	Question(nlohmann::json question);
	std::string getQuestion();
	nlohmann::json getPossibleAnswers();
	unsigned int getCorrentAnswerId();
	std::string getDifficulty();
	std::string getCategory();
};

