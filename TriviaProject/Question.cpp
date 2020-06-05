#include "Question.h"

//
Question::Question(nlohmann::json question) : m_question(question)
{
	nlohmann::json possibleAnswersJson{ {"PossibleAnswers", {}} };
	std::vector<std::string> possibleAnswersVector{ m_question["IncorrectAnswers"].at(0),m_question["IncorrectAnswers"].at(1),m_question["IncorrectAnswers"].at(2), m_question["CorrectAnswer"] };
	std::shuffle(possibleAnswersVector.begin(), possibleAnswersVector.end(), std::default_random_engine(std::chrono::system_clock::now().time_since_epoch().count()));
	int index = 0;
	for (std::string answer : possibleAnswersVector)
	{
		if (answer == std::string(m_question["CorrectAnswer"])) // if answer is the correct one
		{
			m_correctAnswerId = index;
		}
		possibleAnswersJson["PossibleAnswers"].push_back({ {"Answer", answer} });
		index++;
	}
	m_possibleAnswersJson = possibleAnswersJson;
}

//
std::string Question::getQuestion()
{
	return std::string(m_question["Question"]);
}

//
nlohmann::json Question::getPossibleAnswers()
{ 

	return m_possibleAnswersJson;
}

//
int Question::getCorrentAnswerId()
{
	return m_correctAnswerId;
}

//
std::string Question::getDifficulty()
{
	return std::string(m_question["Difficulty"]);
}

//
std::string Question::getCategory()
{
	return std::string(m_question["Category"]);
}