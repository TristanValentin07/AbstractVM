/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** Build
*/

#ifndef BUILD_HPP_
#define BUILD_HPP_

#include <string>
#include <iostream>
#include "Vm.hpp"
#include "Factory.hpp"

class Build {
public:
    Build(Vm& vm);
    ~Build();
    void pop();
    void clear();
    void dup();
    void swap();
    void dump();
    void add();
    void sub();
    void mult();
    void div();
    void mod();
    void load(eOperandType type, const std::string& value);
    void push(eOperandType type, const std::string& value);
    void store(eOperandType type, const std::string& value);
    void assert(eOperandType type, const std::string& value);
    void print();
    void exit();
    bool is_exit();
    std::string get_found_type(eOperandType &type);
    std::string str_inverse(const std::string &str);

private:
    Vm& vm;
    bool question_exit = false;
    std::string found_type;
    bool its_file = false;
    std::string tmp;
    size_t direction;
    std::string operandStr;
    std::string result;
    int count = 0;
    std::vector<std::string> result_vect;
};

#endif /* !BUILD_HPP_ */
