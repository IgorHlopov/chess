#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"

class Bishop : public Piece
{
public:
    Bishop(Color color);
    std::set<Position> getValidMoves(const Position&, const Board&) const override;
};

#endif // BISHOP_H
