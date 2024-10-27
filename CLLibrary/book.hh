#pragma once

#include <memory>
#include <string>
#include <vector>
#include <array>

#include "author.hh"

class Author;  // because of cyclic includes

/**
 * @class Book
 * @brief Represents a book with a title and an author.
 * 
 * The Book class provides methods to access the title and author of the book.
 * It supports initialization with or without specifying the title and author.
 */
class Book
{
public:
    Book();
    Book(const str title, std::shared_ptr<Author> author);
    str getTitle();
    virtual std::vector<std::shared_ptr<Author>> getAuthor();
    virtual str getAuthorName();
protected:
    str mTitle;
    std::shared_ptr<Author> mAuthor;
};