#include <memory>
#include <string>
#include <vector>
#include <array>
#include "bd.hh"

Bd::Bd() : Book(), mArtist(nullptr) {}

Bd::Bd(std::string title, std::shared_ptr<Author> author, std::shared_ptr<Author> artist) : Book(title, author), mArtist(artist)
{
    mArtist->addBook(title);
}

str Bd::getAuthorName()
{
    return mAuthor->getName() + " & " + mArtist->getName();
}

std::vector<std::shared_ptr<Author>> Bd::getAuthor()
{
    return std::vector<std::shared_ptr<Author>>{mAuthor, mArtist};
}
