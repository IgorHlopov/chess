#ifndef GAME_H
#define GAME_H

#include "gamecontroller.h"
#include <QtQuick/QQuickView>
#include <QtQuick/QQuickItem>
#include <QQmlContext>
#include <QAbstractListModel>
#include <QUrl>

class Game : public QAbstractListModel
{
    Q_OBJECT

private:
    Q_DISABLE_COPY(Game)

private:
    enum SquareRoles {
        RowRole = Qt::UserRole + 1,
        ColumnRole,
        ImageRole,
        ValidMoveRole
    };

public:
    explicit Game(QObject *parent = 0);
    int rowCount(const QModelIndex& parent = QModelIndex()) const Q_DECL_OVERRIDE;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    void show();

protected:
    QHash<int, QByteArray> roleNames() const Q_DECL_OVERRIDE;

public slots:
    void gameStateChanged();

private:
    QQuickView m_gameView;
    GameController m_gameController;
};

#endif // GAME_H
