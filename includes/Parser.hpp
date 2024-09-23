/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** Parser
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include "Build.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <sstream>

class Parser {
    public:
        Parser(Build &build);
        void parsing(const std::string &commande);
        std::string del_space(const std::string &str);
        std::vector<std::string> div_command(const std::string &commande);
        void reparse_command(const std::vector<std::string> &part);
        bool isNumeric(const std::string& inputString);
        std::vector<std::string> separate(const std::string &str, char c);
        eOperandType return_type(const std::string &type);
        void init_command();
        void Parsing_file(const std::string &file);

    protected:
    private:
        std::map<std::string, void (Build::*)()> next_command;
        std::vector<std::string> command_list;
        std::map<std::string, void (Build::*)(eOperandType, const std::string &)> command_assert;
        Build &calcul;
};

#endif /* !PARSER_HPP_ */
