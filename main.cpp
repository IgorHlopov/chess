#include <QGuiApplication>
#include "game.h"

int main(int argc, char **argv)
{
    QGuiApplication app(argc, argv);
    Game game;
    game.show();
    return app.exec();
}
