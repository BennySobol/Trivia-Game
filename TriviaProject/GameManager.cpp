#include "GameManager.h"


// GameManager Constructor
GameManager::GameManager() : m_database(SqliteDataBase::getInstance()) {}

// createGame function, 
Game GameManager::createGame(Room room)
{
	Game game(room, m_database->getQuestions(room.getRoomData().questionCount));
	m_games.insert({ room.getRoomData().id, game });
	return game;
}

Game GameManager::getGame(int roomId)
{
	return m_games[roomId];
}

// createGdeleteGameame function, 
bool GameManager::deleteGame(int roomId)
{
	if (m_games.find(roomId) != m_games.end())
	{
		m_games.erase(roomId); // erase game from games 
		return true;
	}
	return false;
}