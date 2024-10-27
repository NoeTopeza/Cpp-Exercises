#include <iostream>
#include <string>

#include "parser.hh"

int main()
{
    Biblio biblio;
    Parser parser(biblio);

    // Command input loop
    std::string input;
    while (true)
    {
        std::cout << "Enter command: ";
        std::getline(std::cin, input);

        if (input == "exit")
        {
            std::cout << "Exiting...\n";
            break;
        }

        parser.processCommand(input);
    }

    return 0;
}