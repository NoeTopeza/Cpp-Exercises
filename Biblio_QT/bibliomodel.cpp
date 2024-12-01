#include "bibliomodel.h"

BiblioModel::BiblioModel(QObject *parent)
    : QAbstractItemModel(parent)
{}

QVariant BiblioModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
}

QModelIndex BiblioModel::index(int row, int column, const QModelIndex &parent) const
{
    // FIXME: Implement me!
}

QModelIndex BiblioModel::parent(const QModelIndex &index) const
{
    // FIXME: Implement me!
}

int BiblioModel::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int BiblioModel::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant BiblioModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}

bool BiblioModel::insertRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(parent, row, row + count - 1);
    // FIXME: Implement me!
    endInsertRows();
    return true;
}

bool BiblioModel::insertColumns(int column, int count, const QModelIndex &parent)
{
    beginInsertColumns(parent, column, column + count - 1);
    // FIXME: Implement me!
    endInsertColumns();
    return true;
}

bool BiblioModel::removeRows(int row, int count, const QModelIndex &parent)
{
    beginRemoveRows(parent, row, row + count - 1);
    // FIXME: Implement me!
    endRemoveRows();
    return true;
}

bool BiblioModel::removeColumns(int column, int count, const QModelIndex &parent)
{
    beginRemoveColumns(parent, column, column + count - 1);
    // FIXME: Implement me!
    endRemoveColumns();
    return true;
}

// void BiblioModel::addBook(const QString& title, const QString& author)
// {
//     beginInsertRows(QModelIndex(), rowCount(), rowCount());
//     m_biblio.addBook(title.toStdString(), author.toStdString());
//     endInsertRows();
// }

// void BiblioModel::removeBook(const QString& title)
// {
//     auto it = std::find_if(m_biblio.getBooks().begin(), m_biblio.getBooks().end(),
//                            [&title](const auto& book){ return book.first == title.toStdString(); });
//     if (it != m_biblio.getBooks().end())
//     {
//         beginRemoveRows(QModelIndex(), it - m_biblio.getBooks().begin(), it - m_biblio.getBooks().begin());
//         m_biblio.removeBook(it->first);
//         endRemoveRows();
//     }
// }

// void BiblioModel::addAuthor(const QString& name)
// {
//     beginInsertRows(QModelIndex(), rowCount(), rowCount());
//     m_biblio.addAuthor(name.toStdString());
//     endInsertRows();
// }

// void BiblioModel::removeAuthor(const QString& name)
// {
//     auto it = std::find_if(m_biblio.getAuthors().begin(), m_biblio.getAuthors().end(),
//                            [&name](const auto& author){ return author.first == name.toStdString(); });
//     if (it != m_biblio.getAuthors().end())
//     {
//         beginRemoveRows(QModelIndex(), it - m_biblio.getAuthors().begin(), it - m_biblio.getAuthors().begin());
//         m_biblio.removeAuthor(it->first);
//         endRemoveRows();
//     }
// }
