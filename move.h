#ifndef MOVE_H
#define MOVE_H

#include "position.h"
#include "piece/piece.h"

class Move
{
private:
    Position m_startPosition;
    Position m_endPosition;
    bool m_wasKill;
    Piece::Type m_pieceType;
    Piece::Color m_pieceColor;

public:     
    Move(const Position&, const Position&, bool, Piece::Type, Piece::Color);
    Move(const Position&, const Position&, bool);
    Position getStartPosition() const;
    Position getEndPosition() const;
    bool wasKill() const;
    Piece::Type getPieceType() const;
    void setPieceType(Piece::Type);
    Piece::Color getPieceColor() const;
    void setPieceColor(Piece::Color);
};

#endif // MOVE_H
