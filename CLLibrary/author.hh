#pragma once

#include <memory>
#include <string>
#include <unordered_set>

typedef std::string str;  // must be defined here to be in book.hh

#include "book.hh"
class Book;  // because of cyclic includes

typedef std::unordered_set<str> booksTitle;

/**
 * @class Author
 * @brief Represents an author with a name and a collection of book titles.
 * 
 * The Author class provides methods to manage the author's name and their books.
 */
class Author
{
public:
    Author(const str name);
    Author(const str name, booksTitle books);

    str getName();

    /**
     * @brief Gets the collection of book titles associated with the author.
     * @return The collection of book titles.
     */
    booksTitle getBooks();

    /**
     * @brief Determines if the author should be removed.
     * @return True if the author should be removed, false otherwise.
     */
    bool toRemove();
    void addBook(const str newBookTitle);
    void removeBook(const str bookTitle);
private:
    str mName;
    booksTitle mBooksTitle;
};