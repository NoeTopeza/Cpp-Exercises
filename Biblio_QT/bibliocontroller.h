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
    void addAuthor(const QString& name);
    void removeBook(const QString& title);
    void removeAuthor(const QString& name);

private:
    BiblioModel* m_model;
    BiblioView* m_view;
};

#endif // BIBLIOCONTROLLER_H
