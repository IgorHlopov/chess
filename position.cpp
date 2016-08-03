#include "position.h"

Position::Position() : m_row(0), m_column(0)
{}

Position::Position(int row, int column) : m_row(row), m_column(column)
{}

int Position::getRow() const
{
    return m_row;
}

int Position::getColumn() const
{
    return m_column;
}

bool Position::operator== (const Position& that) const
{
    return m_row == that.getRow() && m_column == that.getColumn();
}

bool Position::operator!= (const Position& that) const
{
    return !(*this == that);
}

bool Position::operator< (const Position& that) const
{
    if (m_row != that.getRow())
        return m_row < that.getRow();
    else
        return m_column < that.getColumn();
}


