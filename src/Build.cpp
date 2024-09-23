/*
** EPiECH PROJECT, 2024
** Untiled (Workspace)
** File description:
** Build
*/

#include "Format.hpp"
#include "Build.hpp"

Build::Build(Vm &vm) : vm(vm)
{
}

Build::~Build()
{
}

void Build::push(eOperandType type, const std::string &value)
{
    found_type = get_found_type(type);
    vm.pile.push_back(Factory::createOperand(type, value));
}

void Build::pop()
{
    if (vm.pile.empty())
    {
        throw Exception("Pile empty on pop");
    }
    else
    {
        delete vm.pile.back();
        vm.pile.pop_back();
    }
}

void Build::clear()
{
    while (!vm.pile.empty())
    {
        delete vm.pile.back();
        vm.pile.pop_back();
    }
}

void Build::dup()
{
    if (vm.pile.empty())
    {
        throw Exception("Pile empty on dup");
    }
    vm.pile.push_back(vm.Clone(vm.pile.back()));
}

void Build::swap()
{
    if (vm.pile.size() < 2)
    {
        throw Exception("Pile is too small for swap");
    }
    std::swap(vm.pile[vm.pile.size() - 1], vm.pile[vm.pile.size() - 2]);
}

void Build::dump()
{
    for (int i = vm.pile.size() - 1; i >= 0; i--)
    {
        result_vect.insert(result_vect.begin() , vm.pile[i]->toString());
    }
}

void Build::assert(eOperandType type, const std::string &value)
{
    Factory factory;
    if (vm.pile.empty())
    {
        throw Exception("Pile empty");
    }
    if (vm.pile.back()->getType() != type)
    {
        throw Exception("Assert failed, type is not the same");
    }
    IOperand *operand = factory.createOperand(type, value);
    delete operand;
}

void Build::load(eOperandType type, const std::string &value)
{
    (void)type;
    int index = std::stoi(value);
    if (index < 0 || index >= 16)
    {
        throw Exception("Index out of range");
    }
    if (vm.tab[index] == nullptr)
    {
        throw Exception("No value in this index");
    }
    vm.pile.push_back(vm.Clone(vm.tab[index]));
}

void Build::store(eOperandType type, const std::string &value)
{
    (void)type;
    int index = std::stoi(value);
    if (index < 0 || index >= 16)
    {
        throw Exception("Index out of range");
    }
    if (vm.pile.empty())
    {
        throw Exception("Pile empty");
    }
    if (vm.tab[index] != nullptr)
    {
        delete vm.tab[index];
    }
    vm.tab[index] = vm.Clone(vm.pile.back());
    delete vm.pile.back();
    vm.pile.pop_back();
}

void Build::add()
{
    vm.exec_Operation([](IOperand *a, IOperand *b)
                      { return *a + *b; });
}

void Build::sub()
{
    vm.exec_Operation([](IOperand *a, IOperand *b)
                      { return *a - *b; });
}

void Build::mult()
{
    if (found_type == "Int8" || found_type == "Int16" || found_type == "Int32") {
        vm.exec_Operation([](IOperand *a, IOperand *b)
                      { return *a * *b; });
    } else {
        vm.exec_Operation([](IOperand *a, IOperand *b)
                          { return *b * *a; });
    }
}

void Build::div()
{
    vm.exec_Operation([](IOperand *a, IOperand *b)
                      { return *a / *b; });
}

void Build::mod()
{
    vm.exec_Operation([](IOperand *a, IOperand *b)
                      { return *a % *b; });
}

void Build::print()
{
    if (vm.pile.empty())
    {
        throw Exception("Empty stack in print function");
    }
    if (vm.pile.back()->getType() != eOperandType::Int8)
    {
        throw Exception("Print function can only be used with Int8");
    }
    char c = static_cast<char>(std::stoi(vm.pile.back()->toString()));
    std::cout << c << std::endl;
}

void Build::exit()
{
    if (vm.file_mode == true)
    {
        for (int i = result_vect.size() - 1; i >= 0; i--) {
            std::cout << result_vect[i] << std::endl;
        }
    }
    else
    {
        std::cout << ";;" << std::endl;
        for (int i = result_vect.size() - 1; i >= 0; i--) {
            std::cout << result_vect[i] << std::endl;
        }
    }
    question_exit = true;
}

bool Build::is_exit()
{
    if (question_exit)
    {
        return true;
    }
    return false;
}

std::string Build::get_found_type(eOperandType &type)
{
    switch (type)
    {
    case eOperandType::Int8:
        return "int8";
    case eOperandType::Int16:
        return "int16";
    case eOperandType::Int32:
        return "int32";
    case eOperandType::Float:
        return "float";
    case eOperandType::Double:
        return "double";
    default:
        return "No type found";
    }
}

std::string Build::str_inverse(const std::string &str)
{
    std::string reversed = str;
    std::reverse(reversed.begin(), reversed.end());
    return reversed;
}