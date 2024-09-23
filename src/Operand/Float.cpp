/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** Float
*/

#include "Factory.hpp"
#include "Format.hpp"
#include <iostream>
#include <string>
#include <limits>
#include <iomanip>

Float_::Float_(const std::string &valeur)
{
    this->valeur = static_cast<float>(std::stof(valeur));
}

Float_::~Float_() = default;

std::string Float_::toString() const
{
    std::stringstream ss;
    ss.precision(7);
    ss << valeur;
    return ss.str();
}

eOperandType Float_::getType() const
{
    return Float;
}

IOperand* Float_::operator+(const IOperand& value) const
{
    eOperandType valueType = value.getType();
    eOperandType typeMax = std::max(this->getType(), valueType);
    double valeur_a = this->valeur;
    double valeur_b;

    switch (valueType) {
        case Int8:
            valeur_b = std::stof(value.toString());
            break;
        case Int16:
            valeur_b = std::stof(value.toString());
            break;
        case Int32:
            valeur_b = std::stof(value.toString());
            break;
        case Float:
            valeur_b = std::stof(value.toString());
            break;
        case Double:
            valeur_b = std::stof(value.toString());
            break;
    }
    double result = valeur_a + valeur_b;
    std::string result_str = Format::convertDoubleToString(result, Float);

    return Factory::createOperand(typeMax, result_str);
}

IOperand *Float_::operator-(const IOperand &value) const
{
    eOperandType valueType = value.getType();
    eOperandType typeMax = std::max(this->getType(), valueType);
    double valeur_a = this->valeur;
    double valeur_b;

    switch (valueType) {
        case Int8:
            valeur_b = std::stof(value.toString());
            break;
        case Int16:
            valeur_b = std::stof(value.toString());
            break;
        case Int32:
            valeur_b = std::stof(value.toString());
            break;
        case Float:
            valeur_b = std::stof(value.toString());
            break;
        case Double:
            valeur_b = std::stof(value.toString());
            break;
    }
    double result = valeur_a - valeur_b;
    std::string result_str = Format::convertDoubleToString(result, Float);

    return Factory::createOperand(typeMax, result_str);
}

IOperand *Float_::operator*(const IOperand &value) const
{
    eOperandType valueType = value.getType();
    eOperandType typeMax = std::max(this->getType(), valueType);
    double valeur_a = this->valeur;
    double valeur_b;

    switch (valueType) {
        case Int8:
            valeur_b = std::stof(value.toString());
            break;
        case Int16:
            valeur_b = std::stof(value.toString());
            break;
        case Int32:
            valeur_b = std::stof(value.toString());
            break;
        case Float:
            valeur_b = std::stof(value.toString());
            break;
        case Double:
            valeur_b = std::stof(value.toString());
            break;
    }

    double result = valeur_a * valeur_b;
    std::string result_str = Format::convertDoubleToString(result, Float);

    return Factory::createOperand(typeMax, result_str);
}

IOperand *Float_::operator/(const IOperand &value) const
{
    eOperandType valueType = value.getType();
    eOperandType typeMax = std::max(this->getType(), valueType);
    double valeur_a = this->valeur;
    double valeur_b;

    switch (valueType) {
        case Int8:
            valeur_b = std::stof(value.toString());
            break;
        case Int16:
            valeur_b = std::stof(value.toString());
            break;
        case Int32:
            valeur_b = std::stof(value.toString());
            break;
        case Float:
            valeur_b = std::stof(value.toString());
            break;
        case Double:
            valeur_b = std::stof(value.toString());
            break;
    }

    if (valeur_b == 0)
        exit(84);

    double result = valeur_a / valeur_b;
    std::string result_str = Format::convertDoubleToString(result, Float);

    return Factory::createOperand(typeMax, result_str);
}

IOperand *Float_::operator%(const IOperand &value) const
{
    printf("Modulo operation on float is forbidden\n");
    std::cout << value.toString() << std::endl;
    return nullptr;
}
