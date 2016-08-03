import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.2
import QtQuick.Dialogs 1.0

Item {    
    signal startGame
    signal loadGame(url fileToLoad)
    signal prevStep
    signal nextStep
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
            Button {
                Layout.fillWidth: true
                text: "prev"
                onClicked: prevStep()
            }
            Button {
                Layout.fillWidth: true
                text: "next"
                onClicked: nextStep()
            }
        }

        Board {
            Layout.fillWidth: true
            Layout.fillHeight: true
            model: gameModel
        }
    }
}

