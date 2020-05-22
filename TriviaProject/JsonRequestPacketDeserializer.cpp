#include "JsonRequestPacketDeserializer.h"


// this function serializes a deserializer Buffer and returns the deserialized LoginRequest
LoginRequest JsonRequestPacketDeserializer::deserializeLoginRequest(Buffer buffer)
{
	std::string bufferString(buffer.begin(), buffer.end());
    int size = stoi(bufferString.substr(1, 6));
	bufferString = bufferString.substr(6, size);
	nlohmann::json json = nlohmann::json::parse(bufferString);

	return LoginRequest{ json["username"], json["password"] };
}

// this function serializes a deserializer Buffer and returns the deserialized SignupRequest
SignupRequest JsonRequestPacketDeserializer::deserializeSignupRequest(Buffer buffer)
{
	std::string bufferString(buffer.begin(), buffer.end());
	int size = stoi(bufferString.substr(1, 6));
	bufferString = bufferString.substr(6, size);
	nlohmann::json json = nlohmann::json::parse(bufferString);

	return SignupRequest{ json["username"], json["password"], json["email"] };
}