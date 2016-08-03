#ifndef KING_H
#define KING_H

#include "piece.h"

class King : public Piece
{
public:
    King(Color color);
    std::set<Position> getValidMoves(const Position&, const Board&) const override;
};

#endif // KING_H
