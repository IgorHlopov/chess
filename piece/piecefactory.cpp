#include "piecefactory.h"

PieceFactory::PieceFactory()
{}

Piece* PieceFactory::createPiece(Piece::Type type, Piece::Color color)
{
    Piece* piece = nullptr;        
    switch(type)
    {
    case Piece::Type::King:
        piece = new King(color);
        break;
    case Piece::Type::Queen:
        piece = new Queen(color);
        break;
    case Piece::Type::Rook:
        piece = new Rook(color);
        break;
    case Piece::Type::Bishop:
        piece = new Bishop(color);
        break;
    case Piece::Type::Knight:
        piece = new Knight(color);
        break;
    case Piece::Type::Pawn:
        piece = new Pawn(color);
        break;
    }
    return piece;
}
