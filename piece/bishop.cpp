#include "bishop.h"
#include "../board.h"

Bishop::Bishop(Color color) : Piece(Piece::Type::Bishop, color)
{
    setImage(QStringLiteral("qrc:/Images/bishop_") + (isBlack() ? "black" : "white"));
}

std::set<Position> Bishop::getValidMoves(const Position& pos, const Board& board) const
{
    static const std::pair<int,int> steps[4] =
    {
        std::make_pair( 1,1), std::make_pair( 1,-1),
        std::make_pair(-1,1), std::make_pair(-1,-1)
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

