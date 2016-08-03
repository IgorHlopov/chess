import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.2
import QtQuick.Dialogs 1.0

Item {
    signal stopGame
    signal saveGame(url fileToSave)
    signal selectedSquare(int row, int column)

    FileDialog {
        id: saveFileDialog
        title: "Please choose a file for saving"
        selectExisting: false
        onAccepted: saveGame(saveFileDialog.fileUrl)
    }

    ColumnLayout {
        anchors.fill: parent

        RowLayout {
            Layout.margins: 5
            Button {
                Layout.fillWidth: true
                text: "Stop game"
                onClicked: stopGame()
            }
            Button {
                Layout.fillWidth: true
                text: "Save game"
                onClicked: saveFileDialog.open()
            }
        }

        Board {
            Layout.fillWidth: true
            Layout.fillHeight: true
            model: gameModel
        }
    }
}
