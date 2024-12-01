#ifndef BIBLIOVIEW_H
#define BIBLIOVIEW_H

#include <QListView>

class BiblioView : public QListView
{
    Q_OBJECT
public:
    BiblioView(QWidget *parent = nullptr);

private slots:
    void handleSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected);

signals:
    void itemSelected(const QModelIndex &index);
};

#endif // BIBLIOVIEW_H
