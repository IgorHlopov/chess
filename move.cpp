#include "move.h"

Move::Move(const Position& startPos, const Position& endPos,
           bool wasKill, Piece::Type type, Piece::Color color)
    : m_startPosition(startPos), m_endPosition(endPos),
      m_wasKill(wasKill), m_pieceType(type), m_pieceColor(color)
{}

Move::Move(const Position& startPos, const Position& endPos, bool wasKill)
    : m_startPosition(startPos), m_endPosition(endPos), m_wasKill(wasKill)
{}

Position Move::getStartPosition() const
{
    return m_startPosition;
}

Position Move::getEndPosition() const
{
    return m_endPosition;
}

bool Move::wasKill() const
{
    return m_wasKill;
}

Piece::Type Move::getPieceType() const
{
    return m_pieceType;
}

void Move::setPieceType(Piece::Type type)
{
    m_pieceType = type;
}

Piece::Color Move::getPieceColor() const
{
    return m_pieceColor;
}

void Move::setPieceColor(Piece::Color color)
{
    m_pieceColor = color;
}
