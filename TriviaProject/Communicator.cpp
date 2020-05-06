#include "Communicator.h"
#include <mutex>

// global variable
std::mutex mtxForClients;


void sendData(SOCKET sc, std::string message);
std::string getStringPartFromSocket(SOCKET sc, unsigned int bytesNum);


#define PORT 1234

// Communicator constructor
Communicator::Communicator()
{
	_serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (_serverSocket == INVALID_SOCKET)
		throw std::exception(__FUNCTION__ " - socket");
}

// Communicator distructor
Communicator::~Communicator()
{
	try
	{
		closesocket(_serverSocket);
	}
	catch (...) {}
}

// this function starts hendle rRequests
void Communicator::startHendleRequests()
{
	bindAndListen();
}

// this function binds to a port and start listening
void Communicator::bindAndListen()
{
	std::cout << "Starting..." << std::endl;
	struct sockaddr_in sa = { 0 };
	sa.sin_port = htons(PORT);          // port that server will listen for
	sa.sin_family = AF_INET;            // must be AF_INET
	sa.sin_addr.s_addr = INADDR_ANY;    // when there are few ip's for the machine. We will use always "INADDR_ANY"

	// Connects between the socket and the configuration (port and etc..)
	if (bind(_serverSocket, (struct sockaddr*) & sa, sizeof(sa)) == SOCKET_ERROR)
		throw std::exception(__FUNCTION__ " - bind");
	std::cout << "binded" << std::endl;
	// Start listening for incoming requests of clients
	if (listen(_serverSocket, SOMAXCONN) == SOCKET_ERROR)
		throw std::exception(__FUNCTION__ " - listen");
	std::cout << "Starting..." << std::endl;

	while (true)
	{
		SOCKET client_socket = ::accept(_serverSocket, NULL, NULL);
		if (client_socket == INVALID_SOCKET)
		{
			throw std::exception(__FUNCTION__);
		}
		else
		{
			std::unique_lock<std::mutex> locker(mtxForClients);
			std::cout << "New client accepted!" << std::endl;
			locker.unlock();
			LoginRequestHandler* loginRequestHandler = new LoginRequestHandler();
			m_clients.insert(std::make_pair(client_socket, loginRequestHandler));

			sendData(client_socket, "Hello");
			locker.lock();
			std::cout << "Send Hello to client" << std::endl;
			locker.unlock();
			std::thread thread(&Communicator::handleNewClient, std::ref(*this), std::ref(client_socket));
			thread.detach(); // This will allow the program to continue running
		}
	}
}

// this function waits for a client to sent something
void Communicator::handleNewClient(SOCKET clientSocket)
{

	try
	{
		while (true)
		{

			std::string partFromSocket = getStringPartFromSocket(clientSocket, 5);
			if (partFromSocket == "Hello")
			{
				std::unique_lock<std::mutex> locker(mtxForClients);
				std::cout << "Received from client: " << partFromSocket << std::endl;
				locker.unlock();
			}
		}
	}
	catch (...)
	{
		delete m_clients[clientSocket]; // free client loginRequestHandler allocated memory
		m_clients.erase(clientSocket); // erase client from clients map 
		closesocket(clientSocket);
		std::unique_lock<std::mutex> locker(mtxForClients);
		std::cout << "Client " << clientSocket << " has Disconected" << std::endl;
		locker.unlock();
	}

}

// this finction free the loginRequestHandlers allocated memory
void Communicator::clearClientMap()
{
	for (auto client : m_clients)
	{
		delete client.second; // free client loginRequestHandler allocated memory
	}
	m_clients.clear();
}

// send data to socket
void sendData(SOCKET sc, std::string message)
{
	const char* data = message.c_str();

	if (send(sc, data, message.size(), 0) == INVALID_SOCKET)
	{
		throw std::exception("Error while sending message to client");
	}
}

// recieve data from socket according byteSize returns the data as string
std::string getStringPartFromSocket(SOCKET sc, unsigned int bytesNum)
{
	if (bytesNum == 0)
	{
		return (char*)"";
	}

	char* data = new char[bytesNum + 1];
	//int res = recv(sc, data, bytesNum, 0);
	int res = recv(sc, data, 1, MSG_PEEK | MSG_WAITALL);
	if (res == INVALID_SOCKET)
	{
		std::string s = "Error while recieving from socket: ";
		s += std::to_string(sc);
		throw std::exception(s.c_str());
	}

	data[bytesNum] = 0;

	std::string dataFromSocket(data);
	return dataFromSocket;
}