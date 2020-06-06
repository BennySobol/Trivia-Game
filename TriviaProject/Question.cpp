#include "Question.h"

// Question constructor
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

// this function returns the question
std::string Question::getQuestion()
{
	return std::string(m_question["Question"]);
}

// this function returns a json of the possible answers
nlohmann::json Question::getPossibleAnswers()
{ 

	return m_possibleAnswersJson;
}

// this function returns the id of the correct answer
int Question::getCorrentAnswerId()
{
	return m_correctAnswerId;
}

// this function returns the question difficulty
std::string Question::getDifficulty()
{
	return std::string(m_question["Difficulty"]);
}

// this function returns the question category
std::string Question::getCategory()
{
	return std::string(m_question["Category"]);
}