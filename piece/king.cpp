#include "king.h"
#include "../board.h"

King::King(Color color) : Piece(Piece::Type::King, color)
{
    setImage(QStringLiteral("qrc:/Images/king_") + (isBlack() ? "black" : "white"));
}

std::set<Position> King::getValidMoves(const Position& pos, const Board& board) const
{
    static const std::pair<int,int> steps[8] =
    {
        std::make_pair( 1,1), std::make_pair( 1,-1),
        std::make_pair(-1,1), std::make_pair(-1,-1),
        std::make_pair( 1,0), std::make_pair(-1, 0),
        std::make_pair( 0,1), std::make_pair( 0,-1)
    };

    std::set<Position> validMoves;    

    for(auto& step : steps)
    {
        int i = pos.getRow() + step.first;
        int j = pos.getColumn() + step.second;

        if (Board::isInside(i,j))
        {
            if (board.getSquare(i,j).isEmpty() || (board.getSquare(i,j).getPieceColor() != getColor()))
                validMoves.insert(Position(i,j));
        }
    }

    return validMoves;
}

