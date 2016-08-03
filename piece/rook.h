#ifndef ROOK_H
#define ROOK_H

#include "piece.h"

class Rook : public Piece
{
public:
    Rook(Color color);
    std::set<Position> getValidMoves(const Position&, const Board&) const override;
};

#endif // ROOK_H
