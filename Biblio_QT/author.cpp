#include "author.h"

Author::Author(const str name) : mName(name), mBooksTitle({}) {}

Author::Author(const str name, booksTitle books) : mName(name), mBooksTitle(books) {}

str Author::getName() {return mName;}

booksTitle Author::getBooks() {return mBooksTitle;}

bool Author::toRemove() {return mBooksTitle.empty();}

void Author::addBook(const str newBookTitle) {mBooksTitle.insert(newBookTitle);}

void Author::removeBook(const str bookTitle) {mBooksTitle.erase(bookTitle);}
