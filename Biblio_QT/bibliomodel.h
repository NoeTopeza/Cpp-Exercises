#ifndef BIBLIOMODEL_H
#define BIBLIOMODEL_H

#include <QAbstractItemModel>
#include "biblio.h"

class BiblioModel : public QAbstractItemModel
{
    Q_OBJECT

public:
    explicit BiblioModel(QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section,
                        Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const override;

    // Basic functionality:
    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Add data:
    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    bool insertColumns(int column, int count, const QModelIndex &parent = QModelIndex()) override;

    // Remove data:
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    bool removeColumns(int column, int count, const QModelIndex &parent = QModelIndex()) override;

    void addBook(const QString& title, const QString& author);
    void addBd(const QString& title, const QString& author, const QString& artist);
    void addAuthor(const QString& name);
    void removeBook(const QString& title);
    void removeAuthor(const QString& name);

private:
    Biblio *m_biblio;
};

#endif // BIBLIOMODEL_H
