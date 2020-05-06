#include "WSAInitializer.h"
#include "Server.h"
#pragma comment(lib, "Ws2_32.lib")
int main()
{
	try
	{
		WSAInitializer wsaInit;
		Server myServer;
		myServer.run();
	}
	catch (std::exception& e)
	{
		std::cout << "Error occured: " << e.what() << std::endl;
	}
	system("PAUSE");
	return 0;
}