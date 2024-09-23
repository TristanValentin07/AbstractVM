/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** Format
*/

#include "Format.hpp"
#include <iomanip>
#include <sstream>
#include <stdexcept>

std::string Format::convertDoubleToString(double number, eOperandType type)
{
    std::ostringstream oss;
    if (type == eOperandType::Float) {
        oss << std::fixed << std::setprecision(7) << number;
    } else if (type == eOperandType::Double) {
        oss << std::fixed << std::setprecision(15) << number;
    }
    std::string result = oss.str();
    result.erase(result.find_last_not_of('0') + 1, std::string::npos);
    if (result.back() == '.') {
        result.pop_back();
    }
    return result;
}

eOperandType Format::findMorePreciseType(const eOperandType& type, const eOperandType& type2)
{
    return type > type2 ? type : type2;
}

std::string Format::executeOperation(double num1, eOperandType type, double num2, eOperandType type2, char op)
{
    eOperandType preciseType = findMorePreciseType(type, type2);
    double result = 0.0;
    switch (op) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
            } else {
                throw std::invalid_argument("Division by zero");
            }
            break;
        default:
            throw std::invalid_argument("Invalid operation");
    }
    return convertDoubleToString(result, preciseType);
}

int Format::precision(const eOperandType &type)
{
    switch (type) {
        case Int8:
            return 0;
        case Int16:
            return 0;
        case Int32:
            return 0;
        case Float:
            return 7;
        case Double:
            return 15;
    }
    return 0;
}
