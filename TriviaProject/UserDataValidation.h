#pragma once
#include <iostream>
#include <regex>

class UserDataValidation
{
public:
    static bool isUsernameValid(const std::string& username);
    static bool isEmailValid(const std::string& email);
    static bool isPasswordValid(const std::string& password);
    static bool isAddressValid(const std::string& address);
    static bool isPhoneValid(const std::string& phone);
    static bool isBirthDateValid(const std::string& birthDate);
};
