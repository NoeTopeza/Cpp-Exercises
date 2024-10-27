#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

#include "parser.hh"

Parser::Parser(Biblio& biblio) : mBiblio(biblio)
{
    mCommand_map["help"] = std::bind(&Parser::helpCommand, this,std::placeholders::_1);
    mCommand_map["addBook"] = std::bind(&Parser::addBookCommand, this,std::placeholders::_1);
    mCommand_map["addBd"] = std::bind(&Parser::addBdCommand, this,std::placeholders::_1);
    mCommand_map["removeBook"] = std::bind(&Parser::removeBookCommand,this, std::placeholders::_1);
    mCommand_map["addAuthor"] = std::bind(&Parser::addAuthorCommand, this,std::placeholders::_1);
    mCommand_map["removeAuthor"] = std::bind(&Parser::removeAuthorCommand, this, std::placeholders::_1);
    mCommand_map["printAuthor"] = std::bind(&Parser::printAuthorCommand, this, std::placeholders::_1);
    mCommand_map["printBooks"] = std::bind(&Parser::printBooksCommand,this, std::placeholders::_1);
    mCommand_map["printStatus"] = std::bind(&Parser::printStatusCommand, this, std::placeholders::_1);
    mCommand_map["listBooks"] = std::bind(&Parser::printBookListCommand, this, std::placeholders::_1);
    mCommand_map["listAuthors"] = std::bind(&Parser::printAuthorListCommand, this, std::placeholders::_1);
}

std::vector<std::string> split(std::istream& stream, char delimiter = ' ') {
    std::vector<std::string> tokens;
    std::string token;
    
    while (std::getline(stream, token, delimiter)) {
        if (token.empty()) continue;
        tokens.push_back(token);
    }
    
    return tokens;
}

void Parser::processCommand(const std::string &input)
{
    std::istringstream stream(input);
    std::string command;
    std::getline(stream, command, ' ');
    auto args = split(stream);
    auto cmd = mCommand_map.find(command);
    if (cmd != mCommand_map.end()) {
        cmd->second(args);
    } else {
        std::cout << "Unknown command.\n";
    }
}

void Parser::helpCommand(arguments args)
{
    for (const auto& command : mCommand_map)
    {
        std::cout << command.first << '\n';
    }
}

void Parser::addBookCommand(arguments args)
{
    if (args.size() == 2) {
        mBiblio.addBook(args[0], args[1]);
    } else {
        std::cout << "Usage: addBook <bookTitle> <authorName>\n";
    }
}

void Parser::addBdCommand(arguments args)
{
    if (args.size() == 3) {
        mBiblio.addBd(args[0], args[1], args[2]);
    } else {
        std::cout << "Usage: addBd <bookTitle> <authorName> <artistName>\n";
    }
}

void Parser::removeBookCommand(arguments args)
{
    if (args.size() == 1) {
        mBiblio.removeBook(args[0]);
    } else {
        std::cout << "Usage: removeBook <bookTitle>\n";
    }
}

void Parser::addAuthorCommand(arguments args)
{
    if (args.size() == 1) {
        mBiblio.addAuthor(args[0]);
    } else {
        std::cout << "Usage: addAuthor <authorName>\n";
    }
}

void Parser::removeAuthorCommand(arguments args)
{
    if (args.size() == 1) {
        mBiblio.removeAuthor(args[0]);
    } else {
        std::cout << "Usage: removeAuthor <authorName>\n";
    }
}

void Parser::printAuthorCommand(arguments args)
{
    if (args.size() == 1) {
        mBiblio.printAuthorFromTitle(args[0]);
    } else {
        std::cout << "Usage: printAuthor <bookTitle>\n";
    }
}

void Parser::printBooksCommand(arguments args)
{
    if (args.size() == 1) {
        mBiblio.printBooksFromName(args[0]);
    } else {
        std::cout << "Usage: printBooks <authorName>\n";
    }
}

void Parser::printStatusCommand(arguments args)
{
    mBiblio.printBiblioStatus();
}

void Parser::printBookListCommand(arguments args)
{
    mBiblio.printBookList();
}

void Parser::printAuthorListCommand(arguments args)
{
    mBiblio.printAuthorList();
}
