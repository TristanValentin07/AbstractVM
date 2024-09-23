/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** Double
*/

#include "Factory.hpp"
#include "Format.hpp"
#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include <sstream>

Double_::Double_(const std::string &valeur)
{
    this->valeur = static_cast<double>(std::stod(valeur));
}

Double_::~Double_() = default;

std::string Double_::toString() const
{
    std::stringstream ss;
    ss.precision(15);
    ss << valeur;
    return ss.str();
}

eOperandType Double_::getType() const
{
    return Double;
}

IOperand *Double_::operator+(const IOperand &value) const
{
    eOperandType valueType = value.getType();
    eOperandType typeMax = std::max(this->getType(), valueType);
    double valeur_a = this->valeur;
    double valeur_b;

    switch (valueType)
    {
    case Int8:
        valeur_b = std::stod(value.toString());
        break;
    case Int16:
        valeur_b = std::stod(value.toString());
        break;
    case Int32:
        valeur_b = std::stod(value.toString());
        break;
    case Float:
        valeur_b = std::stod(value.toString());
        break;
    case Double:
        valeur_b = std::stod(value.toString());
        break;
    }

    double result = valeur_a + valeur_b;
    std::string result_str = Format::convertDoubleToString(result, Double);

    return Factory::createOperand(typeMax, result_str);
}

IOperand *Double_::operator-(const IOperand &value) const
{
    eOperandType valueType = value.getType();
    eOperandType typeMax = std::max(this->getType(), valueType);
    double valeur_a = this->valeur;
    double valeur_b;

    switch (valueType)
    {
    case Int8:
        valeur_b = std::stod(value.toString());
        break;
    case Int16:
        valeur_b = std::stod(value.toString());
        break;
    case Int32:
        valeur_b = std::stod(value.toString());
        break;
    case Float:
        valeur_b = std::stod(value.toString());
        break;
    case Double:
        valeur_b = std::stod(value.toString());
        break;
    }
    double result = valeur_a - valeur_b;
    std::string result_str = Format::convertDoubleToString(result, Double);

    return Factory::createOperand(typeMax, result_str);
}

IOperand *Double_::operator*(const IOperand &value) const
{
    eOperandType valueType = value.getType();
    eOperandType typeMax = std::max(this->getType(), valueType);
    double valeur_a = this->valeur;
    double valeur_b;

    switch (valueType)
    {
    case Int8:
        valeur_b = std::stod(value.toString());
        break;
    case Int16:
        valeur_b = std::stod(value.toString());
        break;
    case Int32:
        valeur_b = std::stod(value.toString());
        break;
    case Float:
        valeur_b = std::stod(value.toString());
        break;
    case Double:
        valeur_b = std::stod(value.toString());
        break;
    }

    double result = valeur_a * valeur_b;
    std::string result_str = Format::convertDoubleToString(result, Double);

    return Factory::createOperand(typeMax, result_str);
}

IOperand *Double_::operator/(const IOperand &value) const
{
    eOperandType valueType = value.getType();
    eOperandType typeMax = std::max(this->getType(), valueType);
    double valeur_a = this->valeur;
    double valeur_b;

    switch (valueType)
    {
    case Int8:
        valeur_b = std::stod(value.toString());
        break;
    case Int16:
        valeur_b = std::stod(value.toString());
        break;
    case Int32:
        valeur_b = std::stod(value.toString());
        break;
    case Float:
        valeur_b = std::stod(value.toString());
        break;
    case Double:
        valeur_b = std::stod(value.toString());
        break;
    }

    if (valeur_b == 0)
        exit(84);

    double result = valeur_a / valeur_b;
    std::string result_str = Format::convertDoubleToString(result, Double);

    return Factory::createOperand(typeMax, result_str);
}

IOperand *Double_::operator%(const IOperand &value) const
{
    eOperandType valueType = value.getType();
    eOperandType typeMax = std::max(this->getType(), valueType);
    int valeur_a = this->valeur;
    int valeur_b;

    switch (valueType)
    {
    case Int8:
        valeur_b = std::stod(value.toString());
        break;
    case Int16:
        valeur_b = std::stod(value.toString());
        break;
    case Int32:
        valeur_b = std::stod(value.toString());
        break;
    case Float:
        valeur_b = std::stod(value.toString());
        break;
    case Double:
        valeur_b = std::stod(value.toString());
        break;
    }

    if (valeur_b == 0)
        exit(84);

    int result = valeur_a % valeur_b;
    std::string result_str = Format::convertDoubleToString(result, Double);

    return Factory::createOperand(typeMax, result_str);
}
