#ifndef POSITION_H
#define POSITION_H

class Position
{
private:
    int m_row;
    int m_column;

public:
    Position();
    Position(int row, int column);
    int getRow() const;
    int getColumn() const;
    bool operator== (const Position& that) const;
    bool operator!= (const Position& that) const;
    bool operator< (const Position& that) const;
};

#endif // POSITION_H
