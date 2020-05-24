#pragma once
#include "json.hpp"
#include <iostream>
#include <vector>

typedef unsigned char byte;
typedef std::vector<byte> Buffer;

typedef struct LoginRequest
{
	std::string username;
	std::string password;
} LoginRequest;

typedef struct SignupRequest
{
	std::string username;
	std::string password;
	std::string email;
	std::string phone;
	std::string address;
	std::string birthDate;
} SignupRequest;

class JsonRequestPacketDeserializer
{
public:
	static LoginRequest deserializeLoginRequest(Buffer);
	static SignupRequest deserializeSignupRequest(Buffer);
};
