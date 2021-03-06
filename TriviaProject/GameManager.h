#pragma once
#include "SqliteDataBase.h"
#include "Game.h"
#include "Room.h"

class GameManager
{
private:
	IDatabase* m_database;
	std::map<int, Game*> m_games;
public:
	GameManager();
	Game* createGame(Room room);
	Game* getGame(int roomId);
    void tryToDeleteGame(Game* game, std::string username);
	void addGameToStatistics(Game game, std::string username);
};
