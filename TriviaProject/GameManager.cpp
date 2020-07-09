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

// this function tries to delete a given game, (the last player will delete the game)
void GameManager::tryToDeleteGame(Game* game, std::string username)
{
	game->setTryToDeleteGame(username);
	if (!game->isGameCanBeDeleted())
	{
		return;
	} // else
	std::map<int, Game*>::iterator result = std::find_if(m_games.begin(), m_games.end(), [&game](const std::pair<int, Game*>& obj) {return obj.second == game; });
	if (result == m_games.end()) // if game was not found
	{
		return;
	} // else - game is over and every one got the results - delete the game
	delete m_games[result->first];
	m_games.erase(result->first); // erase game from games 
}

// this function adds a game to the user statistics
void GameManager::addGameToStatistics(Game game, std::string username)
{
	GameData gameData = game.getUserData(username);
	m_database->addGameToStatistics(username, gameData.correctAnswerCount, gameData.wrongAnswerCount, gameData.averangeAnswerTime);
}