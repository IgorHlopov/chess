#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"

class Knight : public Piece
{
public:
    Knight(Color color);
    std::set<Position> getValidMoves(const Position&, const Board&) const override;
};

#endif // KNIGHT_H
