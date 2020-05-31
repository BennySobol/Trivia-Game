#include "Server.h"

// this function run the server until 'EXIT' is entered
void Server::run()
{
	std::string input;

	std::thread thread(&Communicator::startHendleRequests, std::ref(m_communicator));
	thread.detach(); // This will allow the program to continue running

	while (true)
	{
		std::cin >> input;
		if (input == EXIT)
		{
			m_communicator.~Communicator(); // call m_communicator destructor
			exit(0);
		}
	}
}


