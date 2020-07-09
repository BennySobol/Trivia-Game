#include "SqliteDataBase.h"
#include <urlmon.h>

// get SqliteDataBase Instance - a Singleton class
SqliteDataBase* SqliteDataBase::getInstance()
{
	static SqliteDataBase instance;

	return &instance;
}

// Constructor - create the database if not exist, or open it
SqliteDataBase::SqliteDataBase()
{
	int doesFileExist = _access(USERS_SQLITE_DB, 0);
	int res = sqlite3_open(USERS_SQLITE_DB, &db);
	if (res != SQLITE_OK) {
		db = nullptr;
		throw  std::exception(__FUNCTION__ "- Can't create the database");
	}
	else if (doesFileExist == FILE_DOES_NOT_EXIST)
	{
		const char* usersTBL = "\
			CREATE TABLE IF NOT EXISTS USERS(\
				ID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,\
				USER_NAME TEXT NOT NULL UNIQUE,\
				PASSWORD TEXT NOT NULL,\
				EMAIL TEXT NOT NULL UNIQUE,\
            	PHONE TEXT,\
            	ADDRESS TEXT,\
         	    BIRTH_DATE INTEGER\
			);";

		res = sqlite3_exec(db, usersTBL, nullptr, nullptr, nullptr);
		if (res != SQLITE_OK) {
			db = nullptr;
			throw  std::exception(__FUNCTION__ "- Can't create usersTBL");
		}

		const char* statisticsTBL = "\
			CREATE TABLE IF NOT EXISTS STATISTICS(\
				ID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,\
                USER_ID INTEGER NOT NULL,\
         	    AVERAGE_ANSWER_TIME DOUBLE,\
         	    NUM_OF_CORRECT_ANSWERS INTEGER,\
         	    NUM_OF_WRONG_ANSWERS INTEGER,\
         	    NUM_OF_GAMES INTEGER,\
				FOREIGN KEY (USER_ID) REFERENCES USERS(ID)\
			);";

		res = sqlite3_exec(db, statisticsTBL, nullptr, nullptr, nullptr);
		if (res != SQLITE_OK) {
			db = nullptr;
			throw  std::exception(__FUNCTION__ "- Can't create statisticsTBL");
		}

		// script to create and fill the question table
		IStream* stream;
		HRESULT result = URLOpenBlockingStream(0, L"https://opentdb.com/api.php?amount=50&type=multiple", &stream, 0, 0);
		if (result != 0)
		{
			throw  std::exception(__FUNCTION__ "- Can't open url blocking stream");
		}
		char buffer[BUFFER_SIZE];
		unsigned long bytesRead;
		std::stringstream stringstream;
		stream->Read(buffer, BUFFER_SIZE, &bytesRead);
		while (bytesRead > 0U)
		{
			stringstream.write(buffer, (long long)bytesRead);
			stream->Read(buffer, BUFFER_SIZE, &bytesRead);
		}
		stream->Release();
		std::string triviaQuestions = stringstream.str();
		nlohmann::json json = nlohmann::json::parse(triviaQuestions);

		const char* questionTBL = "\
			CREATE TABLE IF NOT EXISTS QUESTIONS(\
				ID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,\
			    QUESTION TEXT NOT NULL, \
				CORRECT_ANSWER TEXT NOT NULL,\
                INCORRECT_ANSWER_1 TEXT NOT NULL,\
				INCORRECT_ANSWER_2 TEXT NOT NULL,\
				INCORRECT_ANSWER_3 TEXT NOT NULL,\
				CATEGORY TEXT NOT NULL,\
	            DIFFICULTY TEXT NOT NULL\
			);";

		res = sqlite3_exec(db, questionTBL, nullptr, nullptr, nullptr);
		if (res != SQLITE_OK) {
			db = nullptr;
			throw  std::exception(__FUNCTION__ "- Can't create questionTBL");
		}
		for (auto& item : json["results"].items())
		{
			std::string insertRecords = "INSERT INTO QUESTIONS (QUESTION, CORRECT_ANSWER, INCORRECT_ANSWER_1, INCORRECT_ANSWER_2, INCORRECT_ANSWER_3, CATEGORY, DIFFICULTY) VALUES ('" + base64_encode(item.value()["question"]) + "', '" + base64_encode(item.value()["correct_answer"]) + "', '" + base64_encode(item.value()["incorrect_answers"].at(0)) + "', '" + base64_encode(item.value()["incorrect_answers"].at(1)) + "', '" + base64_encode(item.value()["incorrect_answers"].at(2)) + "', '" + base64_encode(item.value()["category"]) + "', '" + base64_encode(item.value()["difficulty"]) + "');";
			sqlite3_exec(db, insertRecords.c_str(), nullptr, nullptr, nullptr);
		}
	}
}

// Destructor - close the database
SqliteDataBase::~SqliteDataBase()
{
	// close the database
	sqlite3_close(db);
	db = nullptr;
}

// this function checks if a user exist in the database
bool SqliteDataBase::doesUserExist(std::string username)
{
	username = base64_encode(username);
	std::string sqliteCode = "SELECT ID FROM USERS WHERE USER_NAME = " + username + ";";
	std::string id = "";
	sqlite3_exec(db, sqliteCode.c_str(), getRecordFirstValue, &id, nullptr);
	return id != "";
}

// this function checks if a given user has the corect password
bool SqliteDataBase::doesPasswordMatch(std::string username, std::string password) // uml 1 argument
{
	username = base64_encode(username);
	password = base64_encode(password);
	std::string sqliteCode = "SELECT ID FROM USERS WHERE USER_NAME = '" + username + "' AND PASSWORD = '" + password + "';";
	std::string id = "";
	int x= sqlite3_exec(db, sqliteCode.c_str(), getRecordFirstValue, &id, nullptr);
	return id != "";
}

// this function trys to add new user to the database return 2 if username already exist, 3 if email already exist, 1 if secsess
int SqliteDataBase::addNewUser(std::string username, std::string password, std::string email, std::string phone, std::string address, std::string birthDate)
{
	username = base64_encode(username);
	password = base64_encode(password);
	email = base64_encode(email);
	phone = base64_encode(phone);
	address = base64_encode(address);
	birthDate = base64_encode(birthDate);
	char* errmsg;
	std::string insertRecords = "INSERT INTO USERS (USER_NAME, PASSWORD, EMAIL, PHONE, ADDRESS, BIRTH_DATE) VALUES ('" + username + "', '" + password + "', '" + email + "', '" + phone + "', '" + address + "', '" + birthDate + "');";
	int res = sqlite3_exec(db, insertRecords.c_str(), nullptr, nullptr, &errmsg);
	if (res != SQLITE_OK) // if UNIQUE constraint failed
	{
		if (std::string(errmsg) == "UNIQUE constraint failed: USERS.USER_NAME")// if username already exist
		{
			return (int)SignupStatus::USERNAME_EXIST_ERROR;
		}
		return (int)SignupStatus::EMAIL_EXIST_ERROR; // email already exist
	}
    insertRecords = "INSERT INTO STATISTICS (USER_ID, AVERAGE_ANSWER_TIME, NUM_OF_CORRECT_ANSWERS, NUM_OF_WRONG_ANSWERS, NUM_OF_GAMES) VALUES (" + getUserId(username) + ", 0, 0, 0, 0);";
	res = sqlite3_exec(db, insertRecords.c_str(), nullptr, nullptr, nullptr);
	if (res != SQLITE_OK)
	{
		return (int)SignupStatus::SIGNUP_ERROR;
	}
	return (int)SignupStatus::SIGNUP_SUCCESS;
}

// this is a callback function that return a the first record id
int SqliteDataBase::getRecordFirstValue(void* data, int argc, char** argv, char** azColName)
{
	std::string& dateReference = *static_cast<std::string*>(data);

	// use 'dateReference' which is a reference to 'data'
	if (argv[0] != nullptr)
	{
		dateReference = argv[0];
	}

	// returns SQLITE_ABORT to terminate the callbacks
	return SQLITE_ABORT;
}

// the function returns a random json question
std::list<nlohmann::json> SqliteDataBase::getQuestions(int numberOfQuestions)
{
	std::string sqliteCode = "SELECT * FROM QUESTIONS ORDER BY RANDOM() LIMIT "+ std::to_string(numberOfQuestions) +";";
	std::list<nlohmann::json> json;
	int res = sqlite3_exec(db, sqliteCode.c_str(), getQuestionsList, &json, nullptr);
	if (res != SQLITE_OK)
	{
		throw std::exception("Error - There are no questions");
	}
	return json;
}

// this function creats a json question from a given question record (callback function)
int SqliteDataBase::getQuestionsList(void* data, int argc, char** argv, char** azColName)
{
	std::list<nlohmann::json>& json = *static_cast<std::list<nlohmann::json>*>(data);

	// use 'json' which is a reference to 'data'
	std::string s = "{ \"Category\":\"" + base64_decode(argv[6]) + "\",\"Difficulty\" : \"" + base64_decode(argv[7]) + "\",\"Question\" : \"" + base64_decode(argv[1]) + "\",\"CorrectAnswer\" : \"" + base64_decode(argv[2]) + "\",\"IncorrectAnswers\" : [\"" + base64_decode(argv[3]) + "\",\"" + base64_decode(argv[4]) + "\",\"" + base64_decode(argv[5]) + "\"] }";
	json.push_back(nlohmann::json::parse(s));
    // return 0 to continue callbacking
	return 0;
}

// this function returns the avrage time per question of a guven user
double SqliteDataBase::getPlayerAverageAnswerTime(std::string username)
{
	username = base64_encode(username);
	std::string sqliteCode = "SELECT AVERAGE_ANSWER_TIME FROM STATISTICS INNER JOIN USERS ON USER_ID = USERS.ID WHERE USER_NAME = \"" + username + "\";";
	std::string averageAnswerTime = "";
	sqlite3_exec(db, sqliteCode.c_str(), getRecordFirstValue, &averageAnswerTime, nullptr);
	return stof(averageAnswerTime);
}

// this function returns the number of correct answers that a given user had answered
int SqliteDataBase::getNumOfCorrectAnswers(std::string username)
{
	username = base64_encode(username);
	std::string sqliteCode = "SELECT NUM_OF_CORRECT_ANSWERS FROM STATISTICS INNER JOIN USERS ON USER_ID = USERS.ID WHERE USER_NAME = \"" + username + "\";";
	std::string numOfCorrectAnswers = "";
	sqlite3_exec(db, sqliteCode.c_str(), getRecordFirstValue, &numOfCorrectAnswers, nullptr);
	return stoi(numOfCorrectAnswers);
}

// this function returns the number of correct answers that a given user had aswerd
int SqliteDataBase::getNumOfWrongAnswers(std::string username)
{
	username = base64_encode(username);
	std::string sqliteCode = "SELECT NUM_OF_WRONG_ANSWERS FROM STATISTICS INNER JOIN USERS ON USER_ID = USERS.ID WHERE USER_NAME = \"" + username + "\";";
	std::string numOfWrongAnswers = "";
	sqlite3_exec(db, sqliteCode.c_str(), getRecordFirstValue, &numOfWrongAnswers, nullptr);
	return stoi(numOfWrongAnswers);
}

// this function returns the number of games that a given user had played
int SqliteDataBase::getNumOfPlayerGames(std::string username)
{
	username = base64_encode(username);
	std::string sqliteCode = "SELECT NUM_OF_GAMES FROM STATISTICS INNER JOIN USERS ON USER_ID = USERS.ID WHERE USER_NAME = \"" + username + "\";";
	std::string numOfGames = "";
	sqlite3_exec(db, sqliteCode.c_str(), getRecordFirstValue, &numOfGames, nullptr);
	return stoi(numOfGames);
}

// this function creats and returns a list of jsons of the 3 best players
std::list<nlohmann::json> SqliteDataBase::getTheBestPlayers()
{
	std::string sqliteCode = "SELECT USER_NAME, NUM_OF_CORRECT_ANSWERS FROM STATISTICS INNER JOIN USERS ON USER_ID = USERS.ID ORDER BY NUM_OF_CORRECT_ANSWERS DESC LIMIT 3;";
	std::list<nlohmann::json> json;
	sqlite3_exec(db, sqliteCode.c_str(), getBestPlayersList, &json, nullptr);
	return json;
}

// this function creats a json question from a given question record (callback function)
int SqliteDataBase::getBestPlayersList(void* data, int argc, char** argv, char** azColName)
{
	std::list<nlohmann::json>& json = *static_cast<std::list<nlohmann::json>*>(data);
	 
	// use 'json' which is a reference to 'data'
	json.push_back(nlohmann::json{ {"Name", base64_decode(std::string(argv[0])) }, {"NumOfCorrectAnswers", argv[1]} });

	// return 0 to continue callbacking
	return 0;
}

// this function adds a user game results to the database
void SqliteDataBase::addGameToStatistics(std::string username, unsigned int correctAnswerCount, unsigned int wrongAnswerCount, double averangeAnswerTime)
{
	double newAverageAnswerTime = (averangeAnswerTime*(correctAnswerCount + wrongAnswerCount) + getPlayerAverageAnswerTime(username)*(getNumOfCorrectAnswers(username) + getNumOfWrongAnswers(username))) / (getNumOfCorrectAnswers(username) + getNumOfWrongAnswers(username) + correctAnswerCount + wrongAnswerCount);
	// Set precision to 2 digits
	std::ostringstream towDigitsPrecision;
	towDigitsPrecision << std::fixed << std::setprecision(2) << newAverageAnswerTime;
	std::string sqliteCode = "UPDATE STATISTICS SET NUM_OF_CORRECT_ANSWERS = NUM_OF_CORRECT_ANSWERS + "+ std::to_string(correctAnswerCount) + ", NUM_OF_GAMES = NUM_OF_GAMES + 1, NUM_OF_WRONG_ANSWERS = NUM_OF_WRONG_ANSWERS + " + std::to_string(wrongAnswerCount) + ", AVERAGE_ANSWER_TIME = " + towDigitsPrecision.str() + " WHERE USER_ID = \"" + getUserId(base64_encode(username)) + "\";";
	sqlite3_exec(db, sqliteCode.c_str(), nullptr, nullptr, nullptr);
}

// this function returns a given user id in the database
std::string SqliteDataBase::getUserId(std::string username)
{
	std::string sqliteCode = "SELECT ID FROM USERS WHERE USER_NAME = \"" + username + "\";";
	std::string userId = "";
	sqlite3_exec(db, sqliteCode.c_str(), getRecordFirstValue, &userId, nullptr);
	return userId;
}