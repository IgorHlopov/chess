#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"

class Queen : public Piece
{
public:
    Queen(Color color);
    std::set<Position> getValidMoves(const Position&, const Board&) const override;
};

#endif // QUEEN_H
