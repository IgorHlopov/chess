#include "gamecontroller.h"

GameController::GameController(QObject *parent) : QObject(parent)
{}

const Board& GameController::getBoard() const
{
    return m_board;
}

bool GameController::isSetAsValidMove(const Position& position) const
{
    return m_validMoves.find(position) != m_validMoves.end();
}

void GameController::startGame()
{    
    m_gameHistory.reset();
    m_turn = Piece::Color::White;
    m_board.initializeBoard();
    m_isMoveStarted = false;
}

void GameController::stopGame()
{    
    m_board.cleanBoard();
    m_validMoves.clear();
}

void GameController::saveGame(const QUrl& fileToSave)
{    
    m_gameHistory.save(fileToSave);
}

void GameController::loadGame(const QUrl& fileToLoad)
{       
    m_gameHistory.load(fileToLoad);
    m_board.initializeBoard();
    emit gameStateChanged();
}

void GameController::nextStep()
{
    if (m_gameHistory.hasNextMove())
    {
        m_board.moveForward(m_gameHistory.getNextMove());
        emit gameStateChanged();
    }
}

void GameController::prevStep()
{
    if (m_gameHistory.hasValidMove())
    {
        m_board.moveBack(m_gameHistory.getMoveAndBack());
        emit gameStateChanged();
    }
}

void GameController::selectedSquare(int row, int column)
{
    const Square& square = m_board.getSquare(row, column);
    if (!m_isMoveStarted)
    {
        if (!square.isEmpty() && (square.getPieceColor() == m_turn))
        {
            m_moveStartPosition = square.getPosition();
            m_validMoves = square.getPiece().getValidMoves(m_moveStartPosition, m_board);
            m_isMoveStarted = true;
            emit gameStateChanged();
        }
    }
    else
    {
        Position moveToPosition = square.getPosition();
        if (isSetAsValidMove(moveToPosition))
        {
            move(m_moveStartPosition, moveToPosition);
            switchTurn();            
        }
        m_validMoves.clear();
        m_isMoveStarted = false;
        emit gameStateChanged();
    }
}

void GameController::move(const Position& startPos, const Position& endPos)
{    
    const Square& destSquare = m_board.getSquare(endPos.getRow(), endPos.getColumn());
    Move move(startPos, endPos, !destSquare.isEmpty());
    if (!destSquare.isEmpty())
    {
        move.setPieceType(destSquare.getPiece().getType());
        move.setPieceColor(destSquare.getPiece().getColor());
    }

    m_board.moveForward(move);
    m_gameHistory.addMove(move);
}

void GameController::switchTurn()
{
    m_turn = (m_turn == Piece::Color::Black) ? Piece::Color::White : Piece::Color::Black;
}


