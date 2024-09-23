/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** Factory
*/

#include "Type.hpp"
#include "Format.hpp"
#include "Factory.hpp"
#include "IOperand.hpp"

IOperand *Factory::createOperand(eOperandType type, const std::string &value)
{
    switch (type)
    {
    case Int8:
        return createInt8(value);
    case Int16:
        return createInt16(value);
    case Int32:
        return createInt32(value);
    case Float:
        return createFloat(value);
    case Double:
        return createDouble(value);
    default:
        throw std::invalid_argument("Type d'opérande inconnu");
    }
}

IOperand *Factory::createInt8(const std::string &value)
{
    int8_t int8_value;

    try
    {
        int8_value = std::stoi(value);
    }
    catch (const std::exception &e)
    {
        throw std::runtime_error("Cannot convert to int8: " + value);
    }
    if (int8_value < std::numeric_limits<int8_t>::min() || int8_value > std::numeric_limits<int8_t>::max())
    {
        throw std::runtime_error("Bad value for Int8 -> " + value);
    }

    return new Int8_(std::to_string(int8_value));
}

IOperand *Factory::createInt16(const std::string &value)
{
    int16_t int16_value;

    try
    {
        int16_value = std::stoi(value);
    }
    catch (const std::exception &e)
    {
        throw std::runtime_error("Cannot convert to int16: " + value);
    }
    if (int16_value < std::numeric_limits<int16_t>::min() || int16_value > std::numeric_limits<int16_t>::max())
    {
        throw std::runtime_error("Bad value for Int16 -> " + value);
    }

    return new Int16_(std::to_string(int16_value));
}

IOperand *Factory::createInt32(const std::string &value)
{
    int32_t int32_value;

    try
    {
        int32_value = std::stoi(value);
    }
    catch (const std::exception &e)
    {
        throw std::runtime_error("Cannot convert to int32: " + value);
    }
    if (int32_value < std::numeric_limits<int32_t>::min() || int32_value > std::numeric_limits<int32_t>::max())
    {
        throw std::runtime_error("Bad value for Int32 -> " + value);
    }

    return new Int32_(std::to_string(int32_value));
}

IOperand *Factory::createFloat(const std::string &value)
{
    double float_value;

    try
    {
        float_value = std::stof(value);
    }
    catch (const std::exception &e)
    {
        throw std::runtime_error("Cannot convert to Float: " + value);
    }
    if (float_value < std::numeric_limits<float>::min() || float_value > std::numeric_limits<float>::max())
    {
        throw std::runtime_error("Bad value for Float -> " + value);
    }

    return new Float_(Format::convertDoubleToString(float_value, Float));
}

IOperand *Factory::createDouble(const std::string &value)
{
    double double_value;

    try
    {
        double_value = std::stod(value);
    }
    catch (const std::exception &e)
    {
        throw std::runtime_error("Cannot convert to Double: " + value);
    }
    if (double_value < std::numeric_limits<double>::min() || double_value > std::numeric_limits<double>::max())
    {
        throw std::runtime_error("Bad value for Double -> " + value);
    }
    return new Double_(Format::convertDoubleToString(double_value, Double));
}
