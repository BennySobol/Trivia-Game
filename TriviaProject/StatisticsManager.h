#pragma once
#include "SqliteDataBase.h"

class StatisticsManager
{
private:
		IDatabase* m_database;
public:
	StatisticsManager();
	nlohmann::json getStatistics(std::string);
};

