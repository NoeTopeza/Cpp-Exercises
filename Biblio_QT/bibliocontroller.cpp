#include "bibliocontroller.h"
#include <QDebug>

void BiblioController::addBook(const QString& title, const QString& author)
{
    // Validate input
    if (title.isEmpty() || author.isEmpty()) {
        qDebug() << "Error: Book title and author cannot be empty.";
        return;
    }

    // Add book to model
    m_model->addBook(title.toStdString(), author.toStdString());

    // Update view
    emit bookAdded();
}

void BiblioController::addBd(const QString& title, const QString& author, const QString& artist)
{
    // Validate input
    if (title.isEmpty() || author.isEmpty() || artist.isEmpty()) {
        qDebug() << "Error: BD title, author, and artist cannot be empty.";
        return;
    }

    // Add BD to model
    m_model->addBd(title.toStdString(), author.toStdString(), artist.toStdString());

    // Update view
    emit bdAdded();
}

void BiblioController::addAuthor(const QString& name)
{
    // Validate input
    if (name.isEmpty()) {
        qDebug() << "Error: Author name cannot be empty.";
        return;
    }

    // Add author to model
    m_model->addAuthor(name.toStdString());

    // Update view
    emit authorAdded();
}

void BiblioController::removeBook(const QString& title)
{
    // Check if book exists
    if (m_model->getBooks().find(title.toStdString()) == m_model->getBooks().end()) {
        qDebug() << "Error: Book not found.";
        return;
    }

    // Remove book from model
    m_model->removeBook(title.toStdString());

    // Update view
    emit bookRemoved();
}

void BiblioController::removeAuthor(const QString& name)
{
    // Check if author exists
    if (m_model->getAuthors().find(name.toStdString()) == m_model->getAuthors().end()) {
        qDebug() << "Error: Author not found.";
        return;
    }

    // Remove author from model
    m_model->removeAuthor(name.toStdString());

    // Update view
    emit authorRemoved();
}