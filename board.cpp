#include "board.h"

Board::Board()
{
    for(int i = 0; i < BOARD_SIZE; ++i)
        for(int j = 0; j < BOARD_SIZE; ++j)
            m_squares[i][j].reset(new Square(i,j));
}

bool Board::isInside(int row, int column)
{
    return row >= 0 && row < BOARD_SIZE && column >=0 && column < BOARD_SIZE;
}

const Square& Board::getSquare(int row, int column) const
{
    return *(m_squares[row][column]);
}

void Board::cleanBoard()
{
    for(int i = 0; i < BOARD_SIZE; ++i)
        for(int j = 0; j < BOARD_SIZE; ++j)
            m_squares[i][j]->setPiece(nullptr);
}

void Board::initializeBoard()
{
    static const Piece::Type pieceOrder[BOARD_SIZE] =
    {
        Piece::Type::Rook, Piece::Type::Knight, Piece::Type::Bishop, Piece::Type::Queen,
        Piece::Type::King, Piece::Type::Bishop, Piece::Type::Knight, Piece::Type::Rook
    };

    cleanBoard();

    // initialize black pieces
    for(int j = 0; j < BOARD_SIZE; ++j)
    {
      m_squares[0][j]->setPiece(PieceFactory::createPiece(pieceOrder[j], Piece::Color::Black));
      m_squares[1][j]->setPiece(PieceFactory::createPiece(Piece::Type::Pawn, Piece::Color::Black));
    }
    // initialize white pieces
    for(int j = 0; j < BOARD_SIZE; ++j)
    {
      m_squares[6][j]->setPiece(PieceFactory::createPiece(Piece::Type::Pawn, Piece::Color::White));
      m_squares[7][j]->setPiece(PieceFactory::createPiece(pieceOrder[j], Piece::Color::White));
    }    
}

void Board::moveForward(const Move& move)
{
    int startRow = move.getStartPosition().getRow();
    int startCol = move.getStartPosition().getColumn();
    int endRow = move.getEndPosition().getRow();
    int endCol = move.getEndPosition().getColumn();

    m_squares[endRow][endCol]->swapPieces( *(m_squares[startRow][startCol]) );
    m_squares[startRow][startCol]->setPiece(nullptr);
}

void Board::moveBack(const Move& move)
{
    int startRow = move.getStartPosition().getRow();
    int startCol = move.getStartPosition().getColumn();
    int endRow = move.getEndPosition().getRow();
    int endCol = move.getEndPosition().getColumn();

    m_squares[startRow][startCol]->swapPieces( *(m_squares[endRow][endCol]) );
    m_squares[endRow][endCol]->setPiece(
        move.wasKill() ? PieceFactory::createPiece(move.getPieceType(), move.getPieceColor()) : nullptr);
}

