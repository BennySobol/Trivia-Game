#include "UserDataValidation.h"


// check if a given username has more then 4 charecters
bool UserDataValidation::isUsernameValid(const std::string& username)
{
    // define a regular expression
    const std::regex pattern("[^\n]+.{4,}");

    // try to match the string with the regular expression
    return std::regex_match(username, pattern);
}

// check if a given email is like XXXX@XXX.XX(.XXX)...
bool UserDataValidation::isEmailValid(const std::string& email)
{
    // define a regular expression
    const std::regex pattern("(\\w+)@(\\w+)(\\.(\\w+))+");

    // try to match the string with the regular expression
    return std::regex_match(email, pattern);
}

// check if a given password has more then 7 charecters, has more the one- spashial charcter, upper letter, lower letter
bool UserDataValidation::isPasswordValid(const std::string& password)
{
    // define a regular expression
    const std::regex pattern("(?=.*?[A-Z])(?=.*?[a-z])(?=.*?[0-9])(?=.*?[#!@$%^&*]).{8,}");

    // try to match the string with the regular expression
    return std::regex_match(password, pattern);
}

// check if a given address is like Street, Apt, City; Street,Apt,City; Street Apt City; Street, Apt City ...
bool UserDataValidation::isAddressValid(const std::string& address)
{
    // define a regular expression
    const std::regex pattern("([A-z]+)([,]?) ([0-9]+)([,]?) ([A-z]+)");

    // try to match the string with the regular expression
    return std::regex_match(address, pattern);
}

// check if a given phone is like 0X-XXX-XXXX, 0X-XXX XXXX, 0XX-XXX-XXXX, 0XX-XXX XXXX
bool UserDataValidation::isPhoneValid(const std::string& phone)
{
    // define a regular expression
    const std::regex pattern("[0]([0-9]{1,2})-([0-9]{3})?([-\\s]?)([0-9]{4})");

    // try to match the string with the regular expression
    return std::regex_match(phone, pattern);
}

// check if a given birth date is like DD/MM/YYYY,  DD.MM.YYYY
bool UserDataValidation::isBirthDateValid(const std::string& birthDate)
{
    // define a regular expression
    const std::regex pattern("(1[0-2]|0[1-9])[\/](3[01]|[12][0-9]|0[1-9])[\/][0-9]{4}|(1[0-2]|0[1-9])[.](3[01]|[12][0-9]|0[1-9])[.][0-9]{4}");

    // try to match the string with the regular expression
    return std::regex_match(birthDate, pattern);
}