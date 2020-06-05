#include "JsonResponsePacketSerializer.h"

// return string after padding zeros if necessary
std::string JsonResponsePacketSerializer::getPaddedNumber(int num, int digits)
{
	std::ostringstream ostr;
	ostr << std::setw(digits) << std::setfill(ZERO) << num;
	return ostr.str();
}

// this function return a Buffer that represent a json and a message code
Buffer JsonResponsePacketSerializer::serializeResponse(unsigned char code, nlohmann::json json)
{
	Buffer jsonBuffer;
	std::string serializedString = json.dump(); // serialize json to string 
	jsonBuffer.insert(jsonBuffer.begin(), serializedString.begin(), serializedString.end()); // insert the string to the Buffer							
    jsonBuffer.insert(jsonBuffer.begin(), code); // insert the message code at start
	std::string messagLength = getPaddedNumber(jsonBuffer.size(), RESPONSE_JSON_START_INDEX);
	jsonBuffer.insert(++jsonBuffer.begin(), messagLength.begin(), messagLength.end()); // insert the json length
	return jsonBuffer;
}

// this function serializes a ErrorResponse struct and returns the serialized Buffer
Buffer JsonResponsePacketSerializer::serializeResponse(ErrorResponse error)
{
	nlohmann::json json = nlohmann::json{ "Error", error.message };
	return serializeResponse((char)MessageCode::ERROR_MESSAGE, json);
}

// this function serializes a LoginResponse struct and returns the serialized Buffer
Buffer JsonResponsePacketSerializer::serializeResponse(LoginResponse login)
{
	nlohmann::json json = nlohmann::json::object({ { "Status", login.status } });
	return serializeResponse((char)MessageCode::LOGIN, json);
}

// this function serializes a SignupResponse struct and returns the serialized Buffer
Buffer JsonResponsePacketSerializer::serializeResponse(SignupResponse singup)
{
	nlohmann::json json = nlohmann::json{ { "Status", singup.status } };
	return serializeResponse((char)MessageCode::SIGNUP, json);
}

// this function serializes a GetStatisticsResponse struct and returns the serialized Buffer
Buffer JsonResponsePacketSerializer::serializeResponse(GetStatisticsResponse statistics)
{
	nlohmann::json json = nlohmann::json{ statistics.statistics };
	json.push_back({ "Status", statistics.status });
	return serializeResponse((char)MessageCode::STATISTICS, json);
}

// this function serializes a LogoutResponse struct and returns the serialized Buffer
Buffer JsonResponsePacketSerializer::serializeResponse(LogoutResponse logout)
{
	nlohmann::json json = nlohmann::json{ { "Status", logout.status } };
	return serializeResponse((char)MessageCode::LOGOUT, json);
}

// this function serializes a GetRoomsResponse struct and returns the serialized Buffer
Buffer JsonResponsePacketSerializer::serializeResponse(GetRoomsResponse getRooms)
{
	nlohmann::json json = nlohmann::json{ getRooms.rooms};
	json.push_back({ "Status", getRooms.status });
	return serializeResponse((char)MessageCode::GET_ROOMS, json);
}

// this function serializes a GetPlayersInRoomResponse struct and returns the serialized Buffer
Buffer JsonResponsePacketSerializer::serializeResponse(GetPlayersInRoomResponse getPlayersInRoom)
{
	nlohmann::json json = nlohmann::json{ getPlayersInRoom.playersInRoom };
	return serializeResponse((char)MessageCode::GET_PLAYERS_IN_ROOM, json);
}

// this function serializes a JoinRoomResponse struct and returns the serialized Buffer
Buffer JsonResponsePacketSerializer::serializeResponse(JoinRoomResponse joinRoom)
{
	nlohmann::json json = nlohmann::json{ { "Status", joinRoom.status } };
	Buffer buffer = serializeResponse((char)MessageCode::JOIN_ROOM, json);
	return buffer;
}

// this function serializes a CreateRoomResponse struct and returns the serialized Buffer
Buffer JsonResponsePacketSerializer::serializeResponse(CreateRoomResponse createRoom)
{
	nlohmann::json json = nlohmann::json{ { "Status", createRoom.status } };
	return serializeResponse((char)MessageCode::CREATE_ROOM, json);
}

// this function serializes a CloseRoomResponse struct and returns the serialized Buffer
Buffer JsonResponsePacketSerializer::serializeResponse(CloseRoomResponse closeRoom)
{
	nlohmann::json json = nlohmann::json{ { "Status", closeRoom.status } };
	return serializeResponse((char)MessageCode::CLOSE_ROOM, json);
}

// this function serializes a StartGameResponse struct and returns the serialized Buffer
Buffer JsonResponsePacketSerializer::serializeResponse(StartGameResponse startGame)
{
	nlohmann::json json = nlohmann::json{ { "Status", startGame.status } };
	return serializeResponse((char)MessageCode::START_GAME, json);
}

// this function serializes a GetRoomStateResponse struct and returns the serialized Buffer
Buffer JsonResponsePacketSerializer::serializeResponse(GetRoomStateResponse getRoomState)
{
	nlohmann::json json = nlohmann::json{ getRoomState.players };
	json.push_back({ "Status", getRoomState.status });
	json.push_back({ "QuestionCount", getRoomState.questionCount });
	json.push_back({ "HasGameBegun", getRoomState.hasGameBegun });
	json.push_back({ "AnswerTimeout", getRoomState.answerTimeout });
	return serializeResponse((char)MessageCode::GET_ROOM_STATE, json);
}

// this function serializes a LeaveRoomResponse struct and returns the serialized Buffer
Buffer JsonResponsePacketSerializer::serializeResponse(LeaveRoomResponse leaveRoom)
{
	nlohmann::json json = nlohmann::json{ { "Status", leaveRoom.status } };
	return serializeResponse((char)MessageCode::LEAVE_ROOM, json);
}

Buffer JsonResponsePacketSerializer::serializeResponse(GetQuestionResponse getQuestion)
{
	nlohmann::json json = getQuestion.answers;
	json["Status"] = getQuestion.status;
	json["Question"] = getQuestion.question;
	return serializeResponse((char)MessageCode::LEAVE_ROOM, json);
}

Buffer JsonResponsePacketSerializer::JsonResponsePacketSerializer::serializeResponse(LeaveGameResponse leaveGame)
{
	nlohmann::json json = nlohmann::json{ { "Status", leaveGame.status } };
	return serializeResponse((char)MessageCode::LEAVE_ROOM, json);
}

Buffer JsonResponsePacketSerializer::serializeResponse(SubmitAnswerResponse submitAnswer)
{
	nlohmann::json json = nlohmann::json{ { "Status", submitAnswer.status },  { "IsCorrectAnswer", submitAnswer.isCorrectAnswer } };
	return serializeResponse((char)MessageCode::LEAVE_ROOM, json);
}

///////////////////////////////////////////////////// to do
Buffer JsonResponsePacketSerializer::serializeResponse(GetGameResultsResponse getGameResults)
{
	nlohmann::json json = nlohmann::json{ { "Status", getGameResults.status } };
	return serializeResponse((char)MessageCode::LEAVE_ROOM, json);
}


