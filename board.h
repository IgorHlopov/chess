#ifndef BOARD_H
#define BOARD_H

#include "move.h"
#include "square.h"
#include "piece/piecefactory.h"
#include <memory>

class Board
{
public:
    static const int BOARD_SIZE = 8;

private:
    std::unique_ptr<Square> m_squares[BOARD_SIZE][BOARD_SIZE];

public:
    explicit Board();
    static bool isInside(int row, int column);
    const Square& getSquare(int row, int column) const;
    void cleanBoard();
    void initializeBoard();
    void moveForward(const Move&);
    void moveBack(const Move&);    
};

#endif
