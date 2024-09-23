/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** Parser
*/

#include "Parser.hpp"

Parser::Parser(Build &build)
    : calcul(build)
{
    init_command();
}

void Parser::init_command()
{
    command_assert["push"] = &Build::push;
    next_command["pop"] = &Build::pop;
    next_command["dump"] = &Build::dump;
    next_command["add"] = &Build::add;
    next_command["sub"] = &Build::sub;
    next_command["mul"] = &Build::mult;
    next_command["div"] = &Build::div;
    next_command["mod"] = &Build::mod;
    next_command["print"] = &Build::print;
    command_assert["assert"] = &Build::assert;
    next_command["exit"] = &Build::exit;
    command_assert["load"] = &Build::load;
    command_assert["store"] = &Build::store;
    next_command["clear"] = &Build::clear;
    next_command["dup"] = &Build::dup;
    next_command["swap"] = &Build::swap;
}

std::vector<std::string> Parser::div_command(const std::string &commande)
{
    auto parts = separate(commande, ' ');
    return parts;
}

std::string Parser::del_space(const std::string &str)
{
    size_t start = 0;
    size_t end = str.size();

    while (start < end && std::isspace(str[start])) {
        ++start;
    }
    while (end > start && std::isspace(str[end - 1])) {
        --end;
    }
    return str.substr(start, end - start);
}

void Parser::reparse_command(const std::vector<std::string> &part)
{
    if (part.size() < 2) {
        throw Exception("Missing operand for command: " + part[0]);
    }

    auto parts = separate(part[1], '(');

    if (parts.size() < 2) {
        throw Exception("Malformed operand: " + part[1]);
    }

    eOperandType type = return_type(parts[0]);

    if (parts[1].empty()) {
        throw Exception("Missing operand value: " + part[1]);
    }

    size_t closing_parenthesis_position = parts[1].find(')');
    if (closing_parenthesis_position == std::string::npos) {
        throw Exception("Missing closing parenthesis in operand: " + parts[1]);
    }

    std::string value = parts[1].substr(0, closing_parenthesis_position);

    if (!Parser::isNumeric(value)) {
        throw Exception("Value is incorrect or not a number: " + value);
    }

    (calcul.*command_assert[part[0]])(type, value);
}

std::vector<std::string> Parser::separate(const std::string &str, char c)
{
    std::string str_cpy = str;
    std::replace(str_cpy.begin(), str_cpy.end(), '\t', ' ');
    std::vector<std::string> result;
    std::stringstream ss(str_cpy);
    for (std::string part; std::getline(ss, part, c);) {
        part.erase(part.begin(), std::find_if(part.begin(), part.end(), [](unsigned char c2) {
            return !std::isspace(c2);
        }));
        part.erase(std::find_if(part.rbegin(), part.rend(), [](unsigned char c2) {
            return !std::isspace(c2);
        }).base(), part.end());
        if (!part.empty())
            result.push_back(part);
    }
    return result;
}

void Parser::parsing(const std::string &commande)
{
    std::string command_clean = del_space(commande);

    if (command_clean.empty() || command_clean[0] == ';') {
        return;
    }
    auto split_command = div_command(command_clean);
    const std::string& command_name = split_command[0];
    command_list.push_back(command_name);

    if (command_assert.find(command_name) != command_assert.end()) {
        reparse_command(split_command);
    } else if (next_command.find(command_name) != next_command.end()) {
        (calcul.*next_command[command_name])();
    } else {
        throw Exception("Unknown command: " + command_name);
    }
}

bool Parser::isNumeric(const std::string& inputString)
{
    std::istringstream iss(inputString);
    double num;
    iss >> std::noskipws >> num;

    return iss.eof() && !iss.fail();
}

eOperandType Parser::return_type(const std::string &type)
{
    if (type == "int8") {
        return eOperandType::Int8;
    } else if (type == "int16") {
        return eOperandType::Int16;
    } else if (type == "int32") {
        return eOperandType::Int32;
    } else if (type == "float") {
        return eOperandType::Float;
    } else if (type == "double") {
        return eOperandType::Double;
    } else {
        throw Exception("Unknown type: " + type);
    }
}

void Parser::Parsing_file(const std::string &file)
{
    Vm vm;
    Build build(vm);
    Parser parser(build);
    std::ifstream file_stream(file);
    std::string line;
    vm.file_mode = true;
    if (!file_stream.is_open()) {
        throw Exception("Cannot open file: " + file);
    }
    while (std::getline(file_stream, line)) {
        parser.parsing(line);
        if (build.is_exit()) {
            break;
        }
    }
    file_stream.close();
}
