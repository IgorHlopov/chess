import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.2
import QtQuick.Dialogs 1.0

Item {    
    anchors.fill: parent

    signal startGame
    signal loadGame(url fileToLoad)
    signal selectedSquare(int row, int column)

    FileDialog {
        id: loadFileDialog
        title: "Please choose a file for loading"
        selectExisting: true
        onAccepted: loadGame(loadFileDialog.fileUrl)
    }

    ColumnLayout {
        anchors.fill: parent

        RowLayout {
            Layout.margins: 5
            Button {
                Layout.fillWidth: true
                text: "Start game"
                onClicked: startGame()
            }
            Button {
                Layout.fillWidth: true
                text: "Load game"
                onClicked: loadFileDialog.open()
            }
        }

        Board {
            Layout.fillWidth: true
            Layout.fillHeight: true
            model: gameModel
        }
    }
}

