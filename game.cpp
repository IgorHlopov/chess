#include "game.h"

Game::Game(QObject *parent) : QAbstractListModel(parent)
{}

int Game::rowCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent);
    return Board::BOARD_SIZE * Board::BOARD_SIZE;
}

QVariant Game::data(const QModelIndex& index, int role) const
{
    if ((index.row() < 0) || (index.row() >= Board::BOARD_SIZE * Board::BOARD_SIZE))
        return QVariant();

    int row = index.row() / Board::BOARD_SIZE;
    int column = index.row() % Board::BOARD_SIZE;

    const Square& square = m_gameController.getBoard().getSquare(row, column);
    Position position = square.getPosition();

    QVariant roleValue = QVariant();
    switch (role)
    {
    case SquareRoles::RowRole:
        roleValue = position.getRow();
        break;
    case SquareRoles::ColumnRole:
        roleValue = position.getColumn();
        break;
    case SquareRoles::ImageRole:
        roleValue = square.getImage();
        break;
    case SquareRoles::ValidMoveRole:
        roleValue = m_gameController.isSetAsValidMove(position);
        break;
    }

    return roleValue;
}

QHash<int, QByteArray> Game::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[RowRole] = "row";
    roles[ColumnRole] = "column";
    roles[ImageRole] = "image";
    roles[ValidMoveRole] = "validMove";
    return roles;
}

void Game::show()
{
    m_gameView.rootContext()->setContextProperty("gameModel", this);
    m_gameView.setSource(QUrl("qrc:/QML/main_view"));
    m_gameView.setWidth(400);
    m_gameView.setHeight(420);
    m_gameView.setMinimumSize(QSize(200, 210));
    m_gameView.setTitle("Chess");

    QObject::connect(m_gameView.rootObject(), SIGNAL(startGame()),
                     &m_gameController, SLOT(startGame()));
    QObject::connect(m_gameView.rootObject(), SIGNAL(stopGame()),
                     &m_gameController, SLOT(stopGame()));
    QObject::connect(m_gameView.rootObject(), SIGNAL(selectedSquare(int,int)),
                     &m_gameController, SLOT(selectedSquare(int,int)));

    QObject::connect(m_gameView.rootObject(), SIGNAL(loadGame(const QUrl&)),
                     &m_gameController, SLOT(loadGame(const QUrl&)));
    QObject::connect(m_gameView.rootObject(), SIGNAL(saveGame(const QUrl&)),
                     &m_gameController, SLOT(saveGame(const QUrl&)));

    QObject::connect(m_gameView.rootObject(), SIGNAL(prevStep()),
                     &m_gameController, SLOT(prevStep()));
    QObject::connect(m_gameView.rootObject(), SIGNAL(nextStep()),
                     &m_gameController, SLOT(nextStep()));    

    QObject::connect(&m_gameController, SIGNAL(gameStateChanged()),
                     SLOT(gameStateChanged()));

    m_gameView.show();
}

void Game::gameStateChanged()
{
    for(int i = 0; i < Board::BOARD_SIZE * Board::BOARD_SIZE; ++i)
        emit dataChanged(index(i), index(i));
}
