#ifndef GAMEHISTORY_H
#define GAMEHISTORY_H

#include "move.h"
#include <vector>
#include <QUrl>
#include <QDataStream>
#include <QFile>

class GameHistory
{
private:
    std::vector<Move> m_history;
    int m_pointer;

public:
    GameHistory();
    void reset();
    void save(const QUrl& fileToSave);
    void load(const QUrl& fileToLoad);
    void addMove(const Move& move);
    bool hasNextMove() const;
    Move getNextMove();
    bool hasValidMove() const;
    Move getMoveAndBack();
};

#endif // GAMEHISTORY_H
