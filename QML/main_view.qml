import QtQuick 2.0

Item {
    anchors.fill: parent

    signal startGame
    signal stopGame
    signal selectedSquare(int row, int column)
    signal loadGame(url fileToLoad)
    signal saveGame(url fileToSave)
    signal prevStep
    signal nextStep    

    Loader {
        id: viewLoader
        anchors.fill: parent
        source: "qrc:/QML/start_view"
    }

    Connections {
        ignoreUnknownSignals: true
        target: viewLoader.item
        onStartGame: { startGame(); viewLoader.source = "qrc:/QML/game_view" }
        onStopGame: { stopGame(); viewLoader.source = "qrc:/QML/start_view" }
        onLoadGame: { loadGame(fileToLoad); viewLoader.source = "qrc:/QML/load_view" }
        onSaveGame: saveGame(fileToSave)
        onPrevStep: prevStep()
        onNextStep: nextStep()
        onSelectedSquare: {
            if (viewLoader.source == "qrc:/QML/game_view") {
                selectedSquare(row,column)
            }
        }
    }
}
