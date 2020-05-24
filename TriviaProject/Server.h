#pragma once
#include "IDatabase.h"
#include "Communicator.h"
#include <exception>
#include <iostream>
#include <string>
#include <string>

#define EXIT "EXIT"

class Server
{
public:
	Server() = default;
	void run();

private:
	IDatabase* m_database;
	Communicator m_communicator;
};