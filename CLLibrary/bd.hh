#pragma once

#include <memory>
#include <string>
#include <vector>
#include <array>

#include "book.hh"

/**
 * @class Bd
 * @brief A class representing a book with an additional artist.
 * 
 * The Bd class inherits from the Book class
 */
class Bd : public Book
{
public:
    Bd();
    Bd(std::string Title, std::shared_ptr<Author> author, std::shared_ptr<Author> artist);

    /**
     * @brief Get the name of the author & artist
     * @return A string representing the author's and artist's name.
     */
    str getAuthorName() override;
    std::vector<std::shared_ptr<Author>> getAuthor() override;
private:
    std::shared_ptr<Author> mArtist;
};