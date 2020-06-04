#include "Question.h"

//
Question::Question(nlohmann::json question) : m_question(question) {}

//
std::string Question::getQuestion()
{
	return m_question["Question"];
}

//
nlohmann::json Question::getPossibleAnswers()
{ 
	nlohmann::json possibleAnswersJson{ {"PossibleAnswers", {}} };
	std::vector<std::string> possibleAnswersVector{ m_question["IncorrectAnswers"].at(0),m_question["IncorrectAnswers"].at(1),m_question["IncorrectAnswers"].at(2), m_question["CorrectAnswer"] };
	std::shuffle(possibleAnswersVector.begin(), possibleAnswersVector.end(), std::default_random_engine(std::chrono::system_clock::now().time_since_epoch().count()));
	int index = 0;
	for (std::string answer : possibleAnswersVector)
	{
		if (answer == m_question["CorrectAnswer"]) // if answer is the correct one
		{
			m_correctAnswerId = index;
		}
		possibleAnswersJson["PossibleAnswers"].push_back({ {"Answer", answer} });
		index++;
	}
	return possibleAnswersJson;
}

//
unsigned int Question::getCorrentAnswerId()
{
	return m_correctAnswerId;
}

//
std::string Question::getDifficulty()
{
	return m_question["Difficulty"];
}

//
std::string Question::getCategory()
{
	return m_question["Category"];
}