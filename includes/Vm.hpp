/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** Vm
*/

#ifndef VM_HPP_
#define VM_HPP_

#include <iostream>
#include <vector>
#include <functional>
#include "IOperand.hpp"

class Vm {
public:
    Vm();
    ~Vm();
    void exec_Operation(const std::function<IOperand*(IOperand*, IOperand*)>& operation);
    IOperand* Clone(IOperand *value);
    bool check_exit() const;
    void set_exit(bool status);

    IOperand* tab[16] = {nullptr};
    std::vector<IOperand*> pile;
    std::string result_dump;
    std::string is_int;
    bool file_mode = false;
private:
};

#endif /* !VM_HPP_ */
