import QtQuick 2.0

GridView {    
    id: board    
    cellWidth: width/8
    cellHeight: height/8

    delegate: Rectangle {        
        width: board.cellWidth
        height: board.cellHeight
        color: {
            validMove ? "springgreen" : ((row+column) & 1) ? "chocolate" : "corn silk"
        }
        border.color: "black"
        border.width: 1

        Image {
            anchors.centerIn: parent
            width: parent.width*0.75
            height: parent.height*0.75            
            source: image
        }        

        MouseArea {
            anchors.fill: parent            
            onClicked: selectedSquare(row, column)
        }
    }   
}  
