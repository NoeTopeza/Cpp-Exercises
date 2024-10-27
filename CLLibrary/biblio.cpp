#include <algorithm>
#include <format>
#include <iostream>
#include <memory>
#include <unordered_map>
#include <vector>
#include <string>

#include "biblio.hh"
#include "vector_utility.hxx"

Biblio::Biblio() : mBooks({}), mAuthors({}) {}

void Biblio::addBook(const str bookTitle, str authorName)
{
    if (mBooks.find(bookTitle) != mBooks.end())
    {
        std::cout << "This book is already in this library\n";
        return;
    }
    auto author = findOrAddAuthor(authorName);
    mBooks[bookTitle] = std::make_shared<Book>(bookTitle, author);
}

void Biblio::addBd(const str bookTitle, str authorName, str artistName)
{
    if (mBooks.find(bookTitle) != mBooks.end())
    {
        std::cout << "This book is already in this library\n";
        return;
    }
    auto author = findOrAddAuthor(authorName);
    auto artist = findOrAddAuthor(artistName);
    mBooks[bookTitle] = std::make_shared<Bd>(bookTitle, author, artist);
}

void Biblio::addAuthor(const str authorName)
{
    if (mAuthors.find(authorName) != mAuthors.end())
    {
        std::cout << "This author is already in this library\n";
        return;
    }
    auto newAuthor = std::make_shared<Author>(authorName);
    mAuthors[authorName] = newAuthor;
}

std::shared_ptr<Author> Biblio::findOrAddAuthor(const str authorName)
{
    auto author = mAuthors.find(authorName);
    if (author != mAuthors.end())
        return author->second;
    auto newAuthor = std::make_shared<Author>(authorName);
    mAuthors[authorName] = newAuthor;
    return newAuthor;
}

void Biblio::removeBook(const str bookTitle)
{
    auto bookNode = mBooks.extract(bookTitle);  // removes the book from mBooks
    if (bookNode.empty())
    {
        std::cout << std::format("The book {} is not in this library:\n", bookTitle);
        return;
    }
    auto book = bookNode.mapped();

    // Update the author's list, and remove them if their list is empty
    auto authors = book->getAuthor();
    for (const auto &author : authors)
    {
        author->removeBook(bookTitle);
        if (author->toRemove())
            mAuthors.erase(author->getName());
    }
}

void Biblio::removeAuthor(const str authorName)
{
    auto authorNode = mAuthors.extract(authorName);  // removes the author from mAuthors
    if (authorNode.empty())
    {
        std::cout << std::format("The author {} is not in this library:\n", authorName);
        return;
    }
    auto author = authorNode.mapped();

    // removing the author's books from the library
    auto books = author->getBooks();
    for (const auto &bookTitle : books)
        removeBook(bookTitle);
}

void Biblio::printAuthorFromTitle(const str bookTitle)
{
    auto bookNode = mBooks.find(bookTitle);
    if (bookNode == mBooks.end())
    {
        std::cout << std::format("The book {} is not in this library:\n", bookTitle);
        return;
    }
    auto author = bookNode->second->getAuthorName();
    std::cout << std::format("{}'s author is {}\n", bookTitle, author);
}

void Biblio::printBooksFromName(const str authorName)
{
    auto authorNode = mAuthors.find(authorName);
    if (authorNode == mAuthors.end())
    {
        std::cout << std::format("The author {} is not in this library:\n", authorName);
        return;
    }
    auto books = authorNode->second->getBooks();
    std::cout << std::format("The author {} has written the following books in this library:\n", authorName);
    for (const auto& book : books)
        std::cout << book << "\n";
}

void Biblio::printBiblioStatus()
{
    std::cout << std::format("There are currently {} books and {} authors in the library.\n", mBooks.size(), mAuthors.size());
}

void Biblio::printBookList()
{
    for (const auto &book : mBooks)
        std::cout << book.first << '\n';
}

void Biblio::printAuthorList()
{
    for (const auto &author : mAuthors)
        std::cout << author.first << '\n';
}
