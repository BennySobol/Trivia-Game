#pragma once
#include <WinSock2.h>
#include <exception>

class WSAInitializer
{
public:
	WSAInitializer();
	~WSAInitializer();
};

