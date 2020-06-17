#pragma once
#include "RequestHandlerFactory.h"
#include "JsonResponsePacketSerializer.h"
#include <WinSock2.h>
#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <map>


#define BUFFER_SIZE 1024
#define PORT 1234

class Communicator
{
public:
	Communicator();
	~Communicator();
	void startHendleRequests();
private:
	SOCKET _serverSocket;
	std::map<SOCKET, IRequestHandler*> m_clients;
	RequestHandlerFactory* m_handlerFactory;
	void handleNewClient(const SOCKET clientSocket);
	void sendData(const SOCKET sc, const std::string message) const;
	Buffer getStringPartFromSocket(const SOCKET sc, const unsigned int bytesNum) const;
	void bindAndListen();
};

