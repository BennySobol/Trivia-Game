#include "GameManager.h"

// GameManager Constructor
GameManager::GameManager() : m_database(SqliteDataBase::getInstance()) {}

// createGame function creates a game from a given room
Game* GameManager::createGame(Room room)
{
	m_games.insert({ room.getRoomData().id, new Game(room, m_database->getQuestions(room.getRoomData().questionCount)) });
	return m_games[room.getRoomData().id];
}

// this function returns a game for a given room id
Game* GameManager::getGame(int roomId)
{
	return m_games[roomId];
}

// createGdeleteGameame function, 
bool GameManager::deleteGame(int roomId)
{
	if (m_games.find(roomId) != m_games.end())
	{
		delete m_games[roomId];
		m_games.erase(roomId); // erase game from games 
		return true;
	}
	return false;
}

// this function adds a game to the user statistics
void GameManager::addGameToStatistics(Game game, std::string username)
{
	GameData gameData = game.getUserData(username);
	m_database->addGameToStatistics(username, gameData.correctAnswerCount, gameData.wrongAnswerCount, gameData.averangeAnswerTime);
}