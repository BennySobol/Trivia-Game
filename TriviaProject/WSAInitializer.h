#pragma once
#include <WinSock2.h>
#include <exception>

#pragma comment(lib, "Ws2_32.lib")

class WSAInitializer
{
public:
	WSAInitializer();
	~WSAInitializer();
};

