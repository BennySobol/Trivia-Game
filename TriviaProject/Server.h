#pragma once
#include "Communicator.h"
#include <exception>
#include <iostream>

#define EXIT "EXIT"

class Server
{
private:
	Communicator m_communicator;
public:
	Server() = default;
	void run();
};