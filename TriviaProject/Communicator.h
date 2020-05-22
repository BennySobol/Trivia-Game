#pragma once
#include "IDatabase.h"
#include "RequestHandlerFactory.h"
#include "IRequestHandler.h"
#include "LoginRequestHandler.h"
#include "JsonResponsePacketSerializer.h"
#include <map>
#include <WinSock2.h>
#include <iostream>
#include <string>
#include <thread>
#include <mutex>


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
	void sendData(SOCKET sc, std::string message);
	Buffer getStringPartFromSocket(SOCKET sc, unsigned int bytesNum);
};

