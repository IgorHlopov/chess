#include "knight.h"
#include "../board.h"

Knight::Knight(Color color) : Piece(Piece::Type::Knight, color)
{
    setImage(QStringLiteral("qrc:/Images/knight_") + (isBlack() ? "black" : "white"));
}

std::set<Position> Knight::getValidMoves(const Position& pos, const Board& board) const
{
    static const std::pair<int,int> steps[8] =
    {
        std::make_pair( 2,1), std::make_pair( 2,-1),
        std::make_pair( 1,2), std::make_pair( 1,-2),
        std::make_pair(-2,1), std::make_pair(-2,-1),
        std::make_pair(-1,2), std::make_pair(-1,-2)
    };

    std::set<Position> validMoves;

    for(auto& step : steps)
    {
        int i = pos.getRow() + step.first;
        int j = pos.getColumn() + step.second;

        if(Board::isInside(i,j))
        {
            if(board.getSquare(i,j).isEmpty() || (board.getSquare(i,j).getPieceColor() != getColor()))
                validMoves.insert(Position(i,j));
        }
    }

    return validMoves;
}

