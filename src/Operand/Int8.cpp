/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** Int8
*/

#include "Factory.hpp"
#include <iostream>
#include <string>
#include <limits>
#include <iomanip>

Int8_::Int8_(const std::string &valeur)
{
    this->valeur = static_cast<int8_t>(std::stoi(valeur));
}

Int8_::~Int8_() = default;

std::string Int8_::toString() const
{
    return std::to_string(valeur);
}

eOperandType Int8_::getType() const
{
    return Int8;
}

IOperand* Int8_::operator+(const IOperand& value) const
{
    eOperandType valueType = value.getType();
    eOperandType typeMax = std::max(this->getType(), valueType);
    double valeur_a = this->valeur;
    double valeur_b;

    switch (valueType) {
        case Int8:
            valeur_b = std::stoi(value.toString());
            break;
        case Int16:
            valeur_b = std::stoi(value.toString());
            break;
        case Int32:
            valeur_b = std::stoi(value.toString());
            break;
        case Float:
            valeur_b = std::stoi(value.toString());
            break;
        case Double:
            valeur_b = std::stoi(value.toString());
            break;
    }
    double result = valeur_a + valeur_b;

    return Factory::createOperand(typeMax, std::to_string(result));
}

IOperand *Int8_::operator-(const IOperand &value) const
{
    eOperandType valueType = value.getType();
    eOperandType typeMax = std::max(this->getType(), valueType);
    double valeur_a = this->valeur;
    double valeur_b;

    switch (valueType) {
        case Int8:
            valeur_b = std::stoi(value.toString());
            break;
        case Int16:
            valeur_b = std::stoi(value.toString());
            break;
        case Int32:
            valeur_b = std::stoi(value.toString());
            break;
        case Float:
            valeur_b = std::stoi(value.toString());
            break;
        case Double:
            valeur_b = std::stoi(value.toString());
            break;
    }
    double result = valeur_a - valeur_b;

    return Factory::createOperand(typeMax, std::to_string(result));
}

IOperand *Int8_::operator*(const IOperand &value) const
{
    eOperandType valueType = value.getType();
    eOperandType typeMax = std::max(this->getType(), valueType);
    double valeur_a = this->valeur;
    double valeur_b;

    switch (valueType) {
        case Int8:
            valeur_b = std::stoi(value.toString());
            break;
        case Int16:
            valeur_b = std::stoi(value.toString());
            break;
        case Int32:
            valeur_b = std::stoi(value.toString());
            break;
        case Float:
            valeur_b = std::stoi(value.toString());
            break;
        case Double:
            valeur_b = std::stoi(value.toString());
            break;
    }

    double result = valeur_a * valeur_b;

    return Factory::createOperand(typeMax, std::to_string(result));
}

IOperand *Int8_::operator/(const IOperand &value) const
{
    eOperandType valueType = value.getType();
    eOperandType typeMax = std::max(this->getType(), valueType);
    double valeur_a = this->valeur;
    double valeur_b;

    switch (valueType) {
        case Int8:
            valeur_b = std::stoi(value.toString());
            break;
        case Int16:
            valeur_b = std::stoi(value.toString());
            break;
        case Int32:
            valeur_b = std::stoi(value.toString());
            break;
        case Float:
            valeur_b = std::stoi(value.toString());
            break;
        case Double:
            valeur_b = std::stoi(value.toString());
            break;
    }

    if (valeur_b == 0)
        exit(84);

    double result = valeur_a / valeur_b;

    return Factory::createOperand(typeMax, std::to_string(result));
}

IOperand *Int8_::operator%(const IOperand &value) const
{
    eOperandType valueType = value.getType();
    eOperandType typeMax = std::max(this->getType(), valueType);
    int valeur_a = this->valeur;
    int valeur_b;

    switch (valueType) {
        case Int8:
            valeur_b = std::stoi(value.toString());
            break;
        case Int16:
            valeur_b = std::stoi(value.toString());
            break;
        case Int32:
            valeur_b = std::stoi(value.toString());
            break;
        case Float:
            valeur_b = std::stoi(value.toString());
            break;
        case Double:
            valeur_b = std::stoi(value.toString());
            break;
    }

    if (valeur_b == 0)
        exit(84);

    int result = valeur_a % valeur_b;

    return Factory::createOperand(typeMax, std::to_string(result));
}
