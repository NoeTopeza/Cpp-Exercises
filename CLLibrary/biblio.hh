#pragma once

#include <iostream>
#include <memory>
#include <unordered_map>
#include <string>

#include "author.hh"
#include "book.hh"
#include "bd.hh"

typedef std::unordered_map<str, std::shared_ptr<Author>> authors;
typedef std::unordered_map<str, std::shared_ptr<Book>> books;

/**
 * @class Biblio
 * @brief A class to manage a collection of books and authors.
 * 
 * The Biblio class provides functionalities to add and remove books and authors.
 * It also allows printing various details about the collection.
 */


class Biblio
{
public:
    Biblio();

    /**
     * @brief Add a book to the collection.
     * 
     * @param bookTitle The title of the book.
     * @param authorName The name of the author.
     */
    void addBook(const str bookTitle, str authorName);

    /**
     * @brief Add a comic book (BD) to the collection.
     * 
     * @param bookTitle The title of the comic book.
     * @param authorName The name of the author.
     * @param artistName The name of the artist.
     */
    void addBd(const str bookTitle, str authorName, str artistName);

    /**
     * @brief Add an author to the collection.
     * 
     * @param authorName The name of the author.
     */
    void addAuthor(const str authorName);

    /**
     * @brief Remove a book from the collection.
     * 
     * @param bookTitle The title of the book to be removed.
     */
    void removeBook(const str bookTitle);

    /**
     * @brief Remove an author from the collection.
     * 
     * @param authorName The name of the author to be removed.
     */
    void removeAuthor(const str authorName);

    /**
     * @brief Print the author of a given book title.
     * 
     * @param bookTitle The title of the book.
     */
    void printAuthorFromTitle(const str bookTitle);

    /**
     * @brief Print all books written by a given author.
     * 
     * @param authorName The name of the author.
     */
    void printBooksFromName(const str authorName);

    /**
     * @brief Print the current status of the bibliography.
     */
    void printBiblioStatus();

    /**
     * @brief Print the list of all books in the collection.
     */
    void printBookList();

    /**
     * @brief Print the list of all authors in the collection.
     */
    void printAuthorList();

private:
    /**
     * @brief Find an author by name or add a new author if not found.
     * 
     * @param authorName The name of the author.
     * @return std::shared_ptr<Author> A shared pointer to the found or newly added author.
     */
    std::shared_ptr<Author> findOrAddAuthor(const str authorName);
    books mBooks;
    authors mAuthors;
};