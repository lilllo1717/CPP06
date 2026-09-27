#include  "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    (void)other;
    return *this;
}

InputType ScalarConverter::parseInput(const std::string& input)
{
    ParseState state = START;

    for (char c: input)
    {
        switch (state)
        {
            case START:
                if (c == '-' || c == '+')
                    state = AFTER_SIGN;
                else if (c >= '0' && c <= '9')
                    state = INT_DIGITS;
                else if (c == '.')
                    state = POINT_NO_DIGITS;
                else
                    return TYPE_INVALID;
                break;

            case AFTER_SIGN:
                if (c >= '0' && c <= '9')
                    state = INT_DIGITS;
                else if (c == '.')
                    state = POINT_NO_DIGITS;
                else
                    return TYPE_INVALID;
                break;

            case INT_DIGITS:
                if (c >= '0' && c <= '9')
                    state = INT_DIGITS;
                else if (c == '.')
                    state = FRACTION;
                else if (c == 'e' || c == 'E')
                    state = AFTER_EXPONENT;
                else
                    return TYPE_INVALID;
                break;
            
            case POINT_NO_DIGITS:
                if (c >= '0' && c <= '9')
                    state = FRACTION;
                else
                    return TYPE_INVALID;
                break;

            case FRACTION:
                if (c >= '0' && c <= '9')
                    state = FRACTION;
                else if (c == 'e' || c == 'E')
                    state = AFTER_EXPONENT;
                else if (c == 'f' || c == 'F')
                    state = FLOAT_SUFFIX;
                else
                    return TYPE_INVALID;
                break;

            case AFTER_EXPONENT:
                if (c >= '0' && c <= '9')
                    state = AFTER_EXPOMNENT_DIGITS;
                else if (c == '-' || c == '+')
                    state = AFTER_EXPONENT_SIGN;
                else
                    return TYPE_INVALID;
                break;

            case AFTER_EXPOMNENT_DIGITS:
                if (c >= '0' && c <= '9')
                    state = AFTER_EXPOMNENT_DIGITS;
                else if (c == 'f' || c == 'F')
                    state = FLOAT_SUFFIX;
                else
                    return TYPE_INVALID;
                break;

            case AFTER_EXPONENT_SIGN:
                if (c >= '0' && c <= '9')
                    state = AFTER_EXPOMNENT_DIGITS;
                else
                    return TYPE_INVALID;
                break;

            case FLOAT_SUFFIX:
                return TYPE_INVALID;
        }
    }
    switch (state)
    {
        case INT_DIGITS:
            return TYPE_INT;
        case FRACTION:
            case AFTER_EXPOMNENT_DIGITS:
                return TYPE_DOUBLE;
        case FLOAT_SUFFIX:
            return TYPE_FLOAT;
        default:
            return TYPE_INVALID; 
    }

}

 
InputType ScalarConverter::detectType(const std::string& input)
{
    InputType type = TYPE_INVALID;

    if (input.empty())
        return type;
    if (input.size() == 1 && !isdigit(input[0]) && isprint(input[0]))
        return TYPE_CHAR;
    if (input == "-inff" || input == "+inff" || input == "nanf")
        return TYPE_FLOAT;
    if (input == "-inf" || input == "+inf" || input == "nan")
        return TYPE_DOUBLE;
    return parseInput(input);
}


void ScalarConverter::convert(const std::string& input)
{
    InputType type = detectType(input);

}



