/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** Exception
*/

#include "Exception.hpp"

Exception::Exception(const std::string& message) : msg_exception(message)
{

}

Exception::~Exception() noexcept = default;

const char* Exception::what() const noexcept
{
	return msg_exception.c_str();
}
