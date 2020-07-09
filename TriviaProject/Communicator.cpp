#include "Communicator.h"

// global variable
std::mutex mtxForClients;

// Communicator constructor
Communicator::Communicator() : m_handlerFactory(RequestHandlerFactory::getInstance())
{
	_serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (_serverSocket == INVALID_SOCKET)
		throw std::exception(__FUNCTION__ " - socket");
}

// Communicator distructor 
Communicator::~Communicator()
{
	for (auto client : m_clients)
	{
		delete client.second; // free client loginRequestHandler allocated memory
	}
	m_clients.clear();
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
		exit(0);
	std::cout << "binded" << std::endl;
	// Start listening for incoming requests of clients
	if (listen(_serverSocket, SOMAXCONN) == SOCKET_ERROR)
		exit(0);
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
			m_clients.insert(std::make_pair(client_socket, m_handlerFactory->createLoginRequestHandler()));

			std::thread thread(&Communicator::handleNewClient, std::ref(*this), std::ref(client_socket));
			thread.detach(); // This will allow the program to continue running
		}
	}
}

// this function waits for a client to sent something
void Communicator::handleNewClient(const SOCKET clientSocket)
{
	try
	{
		while (true)
		{
			Buffer partFromSocket = getStringPartFromSocket(clientSocket, BUFFER_SIZE);
			if (!partFromSocket.empty())
			{
				RequestInfo requestInfo{ partFromSocket[0], std::time(0), partFromSocket };
				RequestResult requestResult = m_clients[clientSocket]->handleRequest(requestInfo);
				if (requestResult.newHandler != NULL) // if there is new handler
				{
					delete m_clients[clientSocket]; // free the prev client handler allocated memory
					m_clients[clientSocket] = requestResult.newHandler;
				}
				int n = send(clientSocket, &(reinterpret_cast<const char*>(requestResult.response.data())[0]), requestResult.response.size(), 0); // cast the vector to byte and sent it
			}
		}
	}
	catch (...)
	{
		if (m_clients[clientSocket] != NULL)
		{
			RequestResult requestResult = m_clients[clientSocket]->handleRequest(RequestInfo{ (int)MessageCode::CLOSE_ROOM, std::time(0), Buffer() }); // try to close room
			if (requestResult.newHandler != NULL) // if there is new handler
			{
				delete m_clients[clientSocket]; // free the prev client handler allocated memory
				m_clients[clientSocket] = requestResult.newHandler;
			}
			requestResult = m_clients[clientSocket]->handleRequest(RequestInfo{ (int)MessageCode::LEAVE_GAME, std::time(0), Buffer() }); //  try to leave game
			if (requestResult.newHandler != NULL) // if there is new handler
			{
				delete m_clients[clientSocket]; // free the prev client handler allocated memory
				m_clients[clientSocket] = requestResult.newHandler;
			}
			requestResult = m_clients[clientSocket]->handleRequest(RequestInfo{ (int)MessageCode::LEAVE_ROOM, std::time(0), Buffer() }); //  try to leave room
			if (requestResult.newHandler != NULL) // if there is new handler
			{
				delete m_clients[clientSocket]; // free the prev client handler allocated memory
				m_clients[clientSocket] = requestResult.newHandler;
			}
			requestResult = m_clients[clientSocket]->handleRequest(RequestInfo{ (int)MessageCode::LOGOUT, std::time(0), Buffer() }); // singout the user

			delete m_clients[clientSocket]; // free the client handler allocated memory
		}
		m_clients.erase(clientSocket);   // erase client from clients map 
		closesocket(clientSocket);
		std::unique_lock<std::mutex> locker(mtxForClients);
		std::cout << "Client " << clientSocket << " has Disconected" << std::endl;
		locker.unlock();
	}
}

// send data to socket
void Communicator::sendData(const SOCKET sc, const std::string message) const
{
	const char* data = message.c_str();

	if (send(sc, data, message.size(), 0) == INVALID_SOCKET)
	{
		throw std::exception("Error while sending message to client");
	}
}

// recieve data from socket according byteSize returns the data as Buffer
Buffer Communicator::getStringPartFromSocket(const SOCKET socket, const unsigned int bytesNum) const
{
	Buffer buffer(bytesNum);
	if (bytesNum == 0)
	{
		return buffer;
	}

	int result = recv(socket, (char*)&buffer[0], buffer.size(), 0);

	if (result == INVALID_SOCKET)
	{
		std::string error = "Error while recieving from socket: " + std::to_string(socket);
		throw std::exception(error.c_str());
	}

	return buffer;
}
