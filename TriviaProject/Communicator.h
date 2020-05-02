#pragma once
#include <map>
#include <WinSock2.h>
#include <iostream>
#include <string>
#include <thread>

#include "IDatabase.h"
#include "RequestHandlerFactory.h"
#include "IRequestHandler.h"
#include "LoginRequestHandler.h"

class Communicator;

class Communicator
{
public:
	Communicator();
	~Communicator();
	void startHendleRequests();
	void clearClientMap();

private:
	SOCKET _serverSocket;
	std::map<SOCKET, IRequestHandler*> m_clients;

	void bindAndListen();
	void handleNewClient(SOCKET clientSocket);

};

