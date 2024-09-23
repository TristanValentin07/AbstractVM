/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** Vm
*/

#include "Vm.hpp"
#include "Factory.hpp"

Vm::Vm()
{
}

Vm::~Vm()
{
}

void Vm::exec_Operation(const std::function<IOperand *(IOperand *, IOperand *)> &operation)
{
    if (pile.size() < 2)
    {
        throw Exception("Pile is too small for operation");
    }
    IOperand *right = pile.back();
    pile.pop_back();
    IOperand *left = pile.back();
    pile.pop_back();
    IOperand *result = operation(left, right);
    pile.push_back(result);
    delete left;
    delete right;
}

IOperand *Vm::Clone(IOperand *value)
{
    return Factory::createOperand(value->getType(), value->toString());
}
