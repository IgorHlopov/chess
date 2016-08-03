#include "gamehistory.h"
#include <QDebug>

GameHistory::GameHistory()
{}

void GameHistory::reset()
{
    m_history.clear();
    m_pointer = -1;
}

void GameHistory::save(const QUrl &fileToLoad)
{
    QFile file(fileToLoad.fileName());
    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);

    int size = m_history.size();
    out << static_cast<qint32>(size);
    for(int i = 0; i < size; ++i)
    {
        Move move = m_history.at(i);
        out << static_cast<qint32>(move.getStartPosition().getRow());
        out << static_cast<qint32>(move.getStartPosition().getColumn());
        out << static_cast<qint32>(move.getEndPosition().getRow());
        out << static_cast<qint32>(move.getEndPosition().getColumn());
        out << static_cast<bool>(move.wasKill());
        out << static_cast<qint32>(move.getPieceType());
        out << static_cast<qint32>(move.getPieceColor());
    }
}

void GameHistory::load(const QUrl &fileToLoad)
{
    reset();

    QFile file(fileToLoad.fileName());
    file.open(QIODevice::ReadOnly);
    QDataStream in(&file);

    qint32 size;
    in >> size;
    qint32 startRow, startCol, endRow, endCol, type, color;
    bool wasKill;
    for (int i = 0; i < size; ++i)
    {
        in >> startRow >> startCol >> endRow >> endCol >> wasKill >> type >> color;
        m_history.push_back( Move(Position(startRow, startCol), Position(endRow, endCol),
                                 wasKill, static_cast<Piece::Type>(type), static_cast<Piece::Color>(color)) );
    }
}

void GameHistory::addMove(const Move& move)
{
    m_history.push_back(move);
}

bool GameHistory::hasNextMove() const
{
    return m_pointer < (static_cast<int>(m_history.size()) - 1);
}

Move GameHistory::getNextMove()
{
    return m_history.at(++m_pointer);
}

bool GameHistory::hasValidMove() const
{
    return (m_pointer >= 0) && (m_pointer < static_cast<int>(m_history.size()));
}

Move GameHistory::getMoveAndBack()
{
    return m_history.at(m_pointer--);
}


