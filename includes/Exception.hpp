/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** Exception
*/

#ifndef EXCEPTION_HPP_
#define EXCEPTION_HPP_

#include <exception>
#include <string>

class Exception : public std::exception {
public:
    explicit Exception(const std::string& message);
    virtual ~Exception() noexcept;
    virtual const char* what() const noexcept override;

protected:
    std::string msg_exception;

private:
};

#endif /* !EXCEPTION_HPP_ */
