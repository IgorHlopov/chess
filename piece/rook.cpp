#include "rook.h"
#include "../board.h"

Rook::Rook(Color color) : Piece(Piece::Type::Rook, color)
{
    setImage(QStringLiteral("qrc:/Images/rook_") + (isBlack() ? "black" : "white"));
}

std::set<Position> Rook::getValidMoves(const Position& pos, const Board& board) const
{
    static const std::pair<int,int> steps[4] =
    {
        std::make_pair(1,0), std::make_pair(-1, 0),
        std::make_pair(0,1), std::make_pair( 0,-1)
    };

    std::set<Position> validMoves;

    for(auto& step : steps)
    {
        int rowStep = step.first;
        int colStep = step.second;

        for(int i = pos.getRow() + rowStep, j = pos.getColumn() + colStep;
            Board::isInside(i,j); i += rowStep, j += colStep)
        {
            if(board.getSquare(i,j).isEmpty())
                validMoves.insert(Position(i,j));
            else
            {
                if(board.getSquare(i,j).getPieceColor() != getColor())
                    validMoves.insert(Position(i,j));
                break;
            }
        }
    }

    return validMoves;
}
