#ifndef PAWN_H
#define PAWN_H

#include "piece.h"

class Pawn : public Piece
{
public:
    Pawn(Color color);
    std::set<Position> getValidMoves(const Position&, const Board&) const override;
};

#endif // PAWN_H
