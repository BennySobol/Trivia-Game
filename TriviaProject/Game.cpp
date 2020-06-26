#include "Game.h"

// Game constructor
Game::Game(Room room, std::list<nlohmann::json> questions) : m_timePerQuestion(room.getRoomData().timePerQuestion)
{
	for (nlohmann::json question : questions) // add the game questions
	{
		m_questions.push_back(Question(question));
	}
	for(LoggedUser user : room.getLoggedUser()) // add the game players
	{
		m_players.insert({ user.getUsername(), GameData { } }); // default value will be 0 for GameData fields
	}
}

// this function returns a new question for a given user
Question Game::getQuestionForUser(LoggedUser user)
{
	m_players[user.getUsername()].startTimer = time(NULL); // start the timer

	if (++m_players[user.getUsername()].currentQuestionIndex > m_questions.size() || m_players[user.getUsername()].hasFinished) // next question
	{
		throw std::exception("Error, try to hack");
	}
	return m_questions[m_players[user.getUsername()].currentQuestionIndex - 1];
}

// this function allow to submit a answer, the function returns wheter or not the answer is correct
bool Game::submitAnswer(LoggedUser user, unsigned int answerId)
{
	if (!m_players[user.getUsername()].hasFinished) // if the user hasn't answered on all the questions 
	{
		if (m_players[user.getUsername()].wrongAnswerCount + m_players[user.getUsername()].correctAnswerCount == m_questions.size() - 1)
		{  // if the user has answered on all the questions 
			m_players[user.getUsername()].hasFinished = true;
		}
		double timeForTheQuestion = difftime(time(NULL), m_players[user.getUsername()].startTimer);
		if (timeForTheQuestion > m_timePerQuestion)
		{ // if user has wrote script that allows you to not send answer later	
			throw std::exception("Error, try to hack");
		}
		// average = average + ((value - average) / nValues)
		m_players[user.getUsername()].averangeAnswerTime += (timeForTheQuestion - m_players[user.getUsername()].averangeAnswerTime) / (m_players[user.getUsername()].correctAnswerCount + m_players[user.getUsername()].wrongAnswerCount + 1);
		if (answerId == m_questions[m_players[user.getUsername()].currentQuestionIndex - 1].getCorrentAnswerId()) // if the answer is correct
		{
			m_players[user.getUsername()].correctAnswerCount++;
			return true;
		} // else
		m_players[user.getUsername()].wrongAnswerCount++;
		return false;
	}
	throw std::exception("Error, try to hack");
}

// this function do not delete the user because we need the user data at the end of the game
bool Game::removePlayer(LoggedUser user)
{
	if (m_players.find(user.getUsername()) != m_players.end()) // if user is in the game
	{
		m_players[user.getUsername()].hasFinished = true;
		return true;
	}
	return false;
}

// this function returns the game results if all players has finished the game
nlohmann::json Game::getGameResults()
{
	nlohmann::json gameResults{ {"Results", {}} };

	for (std::pair<std::string, GameData> player : m_players)
	{
		if (player.second.hasFinished) // if user has finished game
		{
			// Set precision to 2 digits
			std::ostringstream towDigitsPrecision;
			towDigitsPrecision << std::fixed << std::setprecision(2) << player.second.averangeAnswerTime;
			gameResults["Results"].push_back({ {"Username", player.first}, {"CorrectAnswerCount", player.second.correctAnswerCount}, {"WrongAnswerCount",  player.second.wrongAnswerCount}, {"AverageAnswerTime",  towDigitsPrecision.str()} });
		}
		else // if game was not finished return a null Results
		{
			return nlohmann::json{ {"Results", {}} };
		}
	}
	return gameResults;
}

// this function returns a given user game data
GameData& Game::getUserData(std::string username)
{
	return m_players[username];
}

// this function sets that a given user got the results
void Game::setTryToDeleteGame(std::string username)
{
	m_players[username].hasTryToDeleteGame = true;
}

// this function returns if everyone got the game results
bool Game::isGameCanBeDeleted()
{
	for (std::pair<std::string, GameData> player : m_players)
	{
		if (!player.second.hasTryToDeleteGame) // if the user has not try to delete the game
		{
			return false;
		}
	}
	return true; // game can be deleted
}