/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** main
*/

#include "Build.hpp"
#include "Parser.hpp"
#include <string>

int main(int ac, char **av)
{
    Vm vm;
    Build build(vm);
    Parser parser(build);
    if (ac == 1) {
        std::string line;
        while (std::getline(std::cin, line)) {
            try {
                parser.parsing(line);
                if (build.is_exit()) {
                    return 0;
                }
            } catch (const std::exception &e) {
                std::cerr << e.what() << std::endl;
                return 84;
            }
        }
    } else if (ac == 2) {
        try {
            parser.Parsing_file(av[1]);
        } catch (const std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl;
            return 84;
        }
    }
    return 0;
}
