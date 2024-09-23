/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** Factory
*/

#ifndef FACTORY_HPP_
#define FACTORY_HPP_

#include "IOperand.hpp"
#include "Exception.hpp"
#include "../includes/Operand/Int8.hpp"
#include "../includes/Operand/Int16.hpp"
#include "../includes/Operand/Int32.hpp"
#include "../includes/Operand/Float.hpp"
#include "../includes/Operand/Double.hpp"
#include <string>
#include <array>
#include <iostream>
#include <limits>
#include <functional>
#include <iostream>
#include <vector>

class Factory {
public:
    static IOperand *createOperand(eOperandType type, const std::string &value);

private:
    static IOperand *createInt8(const std::string &value);
    static IOperand *createInt16(const std::string &value);
    static IOperand *createInt32(const std::string &value);
    static IOperand *createFloat(const std::string &value);
    static IOperand *createDouble(const std::string &value);
};

#endif /* !FACTORY_HPP_ */
