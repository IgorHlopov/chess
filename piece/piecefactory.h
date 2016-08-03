#ifndef PIECEFACTORY_H
#define PIECEFACTORY_H

#include "piece.h"
#include "king.h"
#include "queen.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "pawn.h"

class PieceFactory
{
public:
    PieceFactory();
    static Piece* createPiece(Piece::Type type, Piece::Color color);
};

#endif // PIECEFACTORY_H
