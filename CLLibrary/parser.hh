#pragma once
#include <iostream>
#include <unordered_map>
#include <functional>
#include <string>
#include <memory>
#include <vector>
#include <sstream>

#include "biblio.hh"

typedef const std::vector<std::string>& arguments;

class Parser {
public:
    Parser(Biblio& biblio);

    void processCommand(const std::string& input);

private:
    /**
     * @brief Print the list of all available commands in mCommand_map.
     */
    void helpCommand(arguments args);

    //* Biblio's function exposed
    void addBookCommand(arguments args);
    void addBdCommand(arguments args);
    void removeBookCommand(arguments args);
    void addAuthorCommand(arguments args);
    void removeAuthorCommand(arguments args);
    void printAuthorCommand(arguments args);
    void printBooksCommand(arguments args);
    void printStatusCommand(arguments args);
    void printBookListCommand(arguments args);
    void printAuthorListCommand(arguments args);
    
    Biblio& mBiblio;
    std::unordered_map<std::string, std::function<void(arguments)>> mCommand_map;
};
