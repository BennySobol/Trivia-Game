#pragma once
#include "json.hpp"
#include "CodeProtocol.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <sstream>

typedef unsigned char byte;
typedef std::vector<byte> Buffer;

typedef struct ErrorResponse 
{
    std::string  message;
} ErrorResponse; 

typedef struct LoginResponse
{
	unsigned int status;
} LoginResponse;

typedef struct SignupResponse
{
	unsigned int status;
} SignupResponse;

class JsonResponsePacketSerializer
{
public:
	static Buffer serializeResponse(unsigned char code, nlohmann::json j);
	static Buffer serializeResponse(ErrorResponse error);
	static Buffer serializeResponse(LoginResponse login);
	static Buffer serializeResponse(SignupResponse singup);
	static std::string getPaddedNumber(int num, int digits);
};
