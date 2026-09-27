#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <map>
#include <unordered_map>
#include <memory>
#include <vector>
#include <string>
#include <string_view>
#include <cctype>
#include <algorithm>
#include <charconv>
#include <ostream>


#define RED     "\033[31m"
#define GREEN    "\033[32m"
#define PURPLE  "\033[35m"
#define RESET   "\033[0m"

enum InputType
{
    TYPE_CHAR,
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_DOUBLE,
    TYPE_INVALID
};

enum ParseState
{
    START,
    AFTER_SIGN,
    INT_DIGITS,
    POINT_NO_DIGITS,
    FRACTION,
    AFTER_EXPONENT,
    AFTER_EXPOMNENT_DIGITS,
    AFTER_EXPONENT_SIGN,
    FLOAT_SUFFIX,
    INVALID_STATE
};


class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter();

    public:

        void convert(const std::string& input);
        InputType detectType(const std::string& input);
        InputType parseInput(const std::string& input);

};

#endif