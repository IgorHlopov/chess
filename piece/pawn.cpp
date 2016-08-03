#include "pawn.h"
#include "../board.h"

Pawn::Pawn(Color color) : Piece(Piece::Type::Pawn, color)
{
    setImage(QStringLiteral("qrc:/Images/pawn_") + (isBlack() ? "black" : "white"));
}

std::set<Position> Pawn::getValidMoves(const Position& position, const Board& board) const
{
    std::set<Position> validMoves;

    int row = position.getRow();
    int col = position.getColumn();
    int step = (getColor() == Color::White) ? -1 : 1;

    // try move vertically
    if(Board::isInside(row+step,col) && board.getSquare(row+step,col).isEmpty())
    {
        validMoves.insert(Position(row+step,col));
        // one more try further from initial position
        bool isInitRow = (getColor() == Color::White) ? (row == Board::BOARD_SIZE - 2) : (row == 1);
        if(isInitRow && Board::isInside(row+2*step,col) && board.getSquare(row+2*step,col).isEmpty())
            validMoves.insert(Position(row+2*step,col));
    }

    // try kill a piece by diagonal
    if(Board::isInside(row+step,col+1) && !board.getSquare(row+step,col+1).isEmpty()
            && (board.getSquare(row+step,col+1).getPieceColor() != getColor()))
        validMoves.insert(Position(row+step,col+1));
    if(Board::isInside(row+step,col-1) && !board.getSquare(row+step,col-1).isEmpty()
            && (board.getSquare(row+step,col-1).getPieceColor() != getColor()))
        validMoves.insert(Position(row+step,col-1));

    return validMoves;
}

