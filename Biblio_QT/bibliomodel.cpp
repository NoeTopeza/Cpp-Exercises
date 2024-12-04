#include "bibliomodel.h"

BiblioModel::BiblioModel(QObject *parent)
    : QAbstractItemModel(parent)
{}

QVariant BiblioModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole || orientation != Qt::Horizontal)
        return QVariant();

    switch (section) {
    case 0:
        return tr("Title");
    default:
        return QVariant();
    }
}

QModelIndex BiblioModel::index(int row, int column, const QModelIndex &parent) const
{
    if (!hasIndex(row, column, parent))
        return QModelIndex();

    if (!parent.isValid()) {
        // Top-level items are books/authors
        return createIndex(row, column, nullptr);
    }

    // Handle nested items (for tree view)
    auto parentItem = static_cast<const Book*>(parent.internalPointer());
    if (parentItem && row < parentItem->getBooks().size()) {
        return createIndex(row, column, const_cast<Book*>(parentItem));
    }

    return QModelIndex();
}

QModelIndex BiblioModel::parent(const QModelIndex &index) const
{
    if (!index.isValid())
        return QModelIndex();

    auto item = static_cast<const Book*>(index.internalPointer());
    if (item) {
        // For tree view: get the parent author
        auto author = item->getAuthor();
        if (author) {
            auto it = std::find_if(m_biblio.getAuthors().begin(), m_biblio.getAuthors().end(),
                                   [author](const auto& a) { return a.second == author; });
            if (it != m_biblio.getAuthors().end()) {
                return createIndex(std::distance(m_biblio.getAuthors().begin(), it), 0, nullptr);
            }
        }
    }

    return QModelIndex();
}

int BiblioModel::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid()) {
        // Top-level items
        return m_biblio.getBooks().size();
    }

    // Count books for an author in tree view
    auto author = static_cast<const Author*>(parent.internalPointer());
    if (author) {
        return author->getBooks().size();
    }

    return 0;
}

int BiblioModel::columnCount(const QModelIndex &parent) const
{
    return 1; // We're only displaying one column
}

QVariant BiblioModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || role != Qt::DisplayRole)
        return QVariant();

    auto item = static_cast<const Book*>(index.internalPointer());
    if (item) {
        return QString::fromStdString(item->getTitle());
    }

    // For tree view: display author names
    auto author = static_cast<const Author*>(index.internalPointer());
    if (author) {
        return QString::fromStdString(author->getName());
    }

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

void BiblioModel::addBook(const QString& title, const QString& author)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_biblio->addBook(title.toStdString(), author.toStdString());
    endInsertRows();
}

void BiblioModel::addBd(const QString& title, const QString& author, const QString& artist)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_biblio->addBd(title.toStdString(), author.toStdString(), artist.toStdString());
    endInsertRows();
}

void BiblioModel::removeBook(const QString& title)
{
    auto it = std::find_if(m_biblio->getBooks().begin(), m_biblio->getBooks().end(),
                           [&title](const auto& book){ return book.first == title.toStdString(); });
    if (it != m_biblio->getBooks().end())
    {
        beginRemoveRows(QModelIndex(), it - m_biblio->getBooks().begin(), it - m_biblio.getBooks().begin());
        m_biblio->removeBook(it->first);
        endRemoveRows();
    }
}

void BiblioModel::addAuthor(const QString& name)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_biblio->addAuthor(name.toStdString());
    endInsertRows();
}

void BiblioModel::removeAuthor(const QString& name)
{
    auto it = std::find_if(m_biblio->getAuthors().begin(), m_biblio.getAuthors().end(),
                           [&name](const auto& author){ return author.first == name.toStdString(); });
    if (it != m_biblio->getAuthors().end())
    {
        beginRemoveRows(QModelIndex(), it - m_biblio->getAuthors().begin(), it - m_biblio.getAuthors().begin());
        m_biblio->removeAuthor(it->first);
        endRemoveRows();
    }
}
