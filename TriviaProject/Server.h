#pragma once

#include <iostream>
#include <string>


#include "IDatabase.h"
#include "Communicator.h"
#include "RequestHandlerFactory.h"

class Server;

class Server
{
public:
	Server() = default;
	~Server() = default;
	void run();

private:
	IDatabase m_database;
	Communicator m_communicator;
	RequestHandlerFactory m_RequestHandlerFactory;
};