#include <iostream>
#include <sstream>
#include "Api.h"
#include "ShapeFactory.h"

int main() {
    Api api(80, 25);

    std::string input;
    while (true) {
        std::cout << "> ";
        std::getline(std::cin, input);

        if (input == "exit") {
            break;
        }

        std::istringstream iss(input);
        std::string command;
        std::vector<std::string> args;
        iss >> command;
        std::string arg;
        while (iss >> arg) {
            args.push_back(arg);
        }

        api.runCommand(command, args);
    }
}
