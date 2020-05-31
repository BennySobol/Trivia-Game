#include "StatisticsManager.h"

// LoginManager Constructor
StatisticsManager::StatisticsManager() : m_database(SqliteDataBase::getInstance()) {}

// this function returns a json of the statistics
nlohmann::json StatisticsManager::getStatistics(std::string username)
{
	nlohmann::json json = { {"UserStatistics",{{"CorrectAnswers", std::to_string(m_database->getNumOfCorrectAnswers(username))}, {"PlayerGames", std::to_string(m_database->getNumOfPlayerGames(username))}, {"TotalAnswers", std::to_string(m_database->getNumOfTotalAnswers(username)) }, { "AverageAnswerTime", std::to_string(m_database->getPlayerAverageAnswerTime(username)) } }}, { "HighScores", {} } };

	std::list<nlohmann::json> theBestPlayers = m_database->getTheBestPlayers();
	for (nlohmann::json player : theBestPlayers)
	{
		json["HighScores"].push_back(player);
	}
	return json;
}
