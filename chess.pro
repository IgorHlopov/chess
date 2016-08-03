TEMPLATE = app

QT += qml quick

CONFIG += c++11

SOURCES += main.cpp \
    board.cpp \
    game.cpp \
    gamecontroller.cpp \
    gamehistory.cpp \
    move.cpp \
    position.cpp \
    square.cpp \
    piece/bishop.cpp \
    piece/king.cpp \
    piece/knight.cpp \
    piece/pawn.cpp \
    piece/piece.cpp \
    piece/piecefactory.cpp \
    piece/queen.cpp \
    piece/rook.cpp

RESOURCES += \
    resource.qrc

HEADERS += \
    board.h \
    game.h \
    gamecontroller.h \
    gamehistory.h \
    move.h \
    position.h \
    square.h \
    piece/bishop.h \
    piece/king.h \
    piece/knight.h \
    piece/pawn.h \
    piece/piece.h \
    piece/piecefactory.h \
    piece/queen.h \
    piece/rook.h

DESTDIR = build/

OBJECTS_DIR = $$DESTDIR/.obj
MOC_DIR = $$DESTDIR/.moc
RCC_DIR = $$DESTDIR/.qrc
UI_DIR = $$DESTDIR/.ui
