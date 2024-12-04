#ifndef BIBLIOCONTROLLER_H
#define BIBLIOCONTROLLER_H

#include "bibliomodel.h"
#include "biblioview.h"
#include <QObject>

class BiblioController : public QObject
{
    Q_OBJECT
public:
    explicit BiblioController(QObject *parent = nullptr);
    void addBook(const QString& title, const QString& author);
    void addBd(const QString& title, const QString& author, const QString& artist);
    void addAuthor(const QString& name);
    void removeBook(const QString& title);
    void removeAuthor(const QString& name);

signals:
    void bookAdded();
    void bdAdded();
    void authorAdded();
    void bookRemoved();
    void authorRemoved();

private:
    BiblioModel* m_model;
    BiblioView* m_view;
};

#endif // BIBLIOCONTROLLER_H
