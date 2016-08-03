#ifndef SQUARE_H
#define SQUARE_H

#include "position.h"
#include "piece/piece.h"
#include <QString>
#include <memory>

class Square
{    
private:    
    Position m_position;
    std::unique_ptr<Piece> m_piece;

public:    
    explicit Square(int row, int column, Piece* piece = nullptr);    
    Position getPosition() const;
    const Piece& getPiece() const;
    void setPiece(Piece* piece);
    Piece::Color getPieceColor() const;
    QString getImage() const;
    bool isEmpty() const;
    void swapPieces(Square& that);
};

#endif // SQUARE_H

