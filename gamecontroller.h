#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "board.h"
#include "gamehistory.h"
#include <QObject>
#include <QUrl>
#include <set>

class GameController : public QObject
{
    Q_OBJECT

public:
    explicit GameController(QObject *parent = 0);
    const Board& getBoard() const;
    bool isSetAsValidMove(const Position& position) const;    

signals:
    void gameStateChanged();

public slots:
    void startGame();
    void loadGame(const QUrl&);
    void stopGame();
    void saveGame(const QUrl&);
    void prevStep();
    void nextStep();
    void selectedSquare(int row, int column);

private:    
    void move(const Position&, const Position&);
    void switchTurn();

private:
    GameHistory m_gameHistory;
    Board m_board;
    Piece::Color m_turn;
    bool m_isMoveStarted;
    Position m_moveStartPosition;
    std::set<Position> m_validMoves;
};

#endif // GAMECONTROLLER_H
