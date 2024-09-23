/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** IOperand
*/

#ifndef IOPERAND_HPP_
#define IOPERAND_HPP_

#include <string>
#include "Type.hpp"

class IOperand
{
    public :
        virtual std::string toString() const = 0;
        virtual eOperandType getType() const = 0;
        virtual IOperand *operator +(const IOperand &rhs) const = 0;
        virtual IOperand *operator -(const IOperand &rhs) const = 0;
        virtual IOperand *operator *(const IOperand &rhs) const = 0;
        virtual IOperand *operator /(const IOperand &rhs) const = 0;
        virtual IOperand *operator %(const IOperand &rhs) const = 0;
        virtual ~IOperand () {}
};

#endif /* !IOPERAND_HPP_ */
