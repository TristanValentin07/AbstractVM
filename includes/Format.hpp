/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** Format
*/

#ifndef FORMAT_HPP_
#define FORMAT_HPP_

#include <iostream>
#include "IOperand.hpp"
#include "Factory.hpp"
#include <string>

class Format {
    public:
        static std::string convertDoubleToString(double number, eOperandType type);
        static eOperandType findMorePreciseType(const eOperandType& type, const eOperandType& type2);
        static std::string executeOperation(double num1, eOperandType type, double num2, eOperandType type2, char op);
        static int precision(const eOperandType &type);

    protected:
    private:
};

#endif /* !FORMAT_HPP_ */
