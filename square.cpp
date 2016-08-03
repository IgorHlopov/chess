#include "square.h"

Square::Square(int row, int column, Piece* piece)
    : m_position(row, column), m_piece(piece)
{}

Position Square::getPosition() const
{
    return m_position;
}

const Piece& Square::getPiece() const
{
    return *m_piece;
}

void Square::setPiece(Piece* piece)
{
    m_piece.reset(piece);
}

QString Square::getImage() const
{
    return (m_piece ? m_piece->getImage() : "");
}

Piece::Color Square::getPieceColor() const
{
    return m_piece->getColor();
}

bool Square::isEmpty() const
{
    return m_piece == nullptr;
}

void Square::swapPieces(Square& that)
{
    m_piece.swap(that.m_piece);
}
