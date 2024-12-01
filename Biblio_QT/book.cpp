#include <memory>
#include <vector>

#include "book.h"

Book::Book() : mTitle(""), mAuthor(nullptr) {}

Book::Book(const str title, std::shared_ptr<Author> author) : mTitle(title), mAuthor(author)
{
    mAuthor->addBook(title);
}

str Book::getTitle() {return mTitle;}

std::vector<std::shared_ptr<Author>> Book::getAuthor()
{
    return std::vector<std::shared_ptr<Author>>{mAuthor};
}

str Book::getAuthorName()
{
    return mAuthor->getName();
}
