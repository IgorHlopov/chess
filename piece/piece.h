#ifndef PIECE_H
#define PIECE_H

#include "position.h"
#include <QString>
#include <utility>
#include <set>

class Board;

class Piece
{
public:
    enum class Type { King, Queen, Knight, Bishop, Rook, Pawn };
    enum class Color { Black, White };

private:
    Type m_type;
    Color m_color;
    QString m_image;

protected:
    void setImage(const QString& image);

public:
    Piece(Type type, Color color);
    virtual ~Piece();
    Type getType() const;
    Color getColor() const;
    QString getImage() const;    
    bool isBlack() const;
    bool isWhite() const;

    virtual std::set<Position> getValidMoves(const Position&, const Board&) const = 0;
};

#endif // PIECE_H
