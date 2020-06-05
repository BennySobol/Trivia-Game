#include "Game.h"

Game::Game(Room room, std::list<nlohmann::json> questions)
{
	for (nlohmann::json question : questions)
	{
		m_questions.push_back(Question(question));
	}
	for(LoggedUser user : room.getUsers())
	{
		m_players.insert({ user.getUsername(), GameData{0, 0, 0, 0} });
	}
}
Question Game::getQuestionForUser(LoggedUser user)
{
	if (++m_players.at(user.getUsername()).currentQuestionIndex >= m_questions.size()) // next question
	{
		throw std::exception("Error, try to hack");
	}
	return m_questions[m_players.at(user.getUsername()).currentQuestionIndex];
}

bool Game::submitAnswer(LoggedUser user, unsigned int answerId, unsigned int averangeTime)
{
	m_players.at(user.getUsername()).averangeAnswerTime += (averangeTime - m_players.at(user.getUsername()).averangeAnswerTime) / (m_players.at(user.getUsername()).correctAnswerCount + m_players.at(user.getUsername()).wrongAnswerCount + 1);
	if (answerId = m_questions[m_players.at(user.getUsername()).currentQuestionIndex].getCorrentAnswerId())
	{
		m_players.at(user.getUsername()).correctAnswerCount++;
		return true;
	}
	m_players.at(user.getUsername()).wrongAnswerCount++;
	return false;
}

bool Game::removePlayer(LoggedUser user)
{
	if (m_players.find(user.getUsername()) != m_players.end())
	{
		m_players.erase(user.getUsername()); // erase user from game 
		return true;
	}
	return false;
}
