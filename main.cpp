#include <QApplication>
#include "mainwindow.h"
#include "tile.h"
#include "piece.h"
int count=0,turn=1,exp[60],max=0;
int wR,wC,bR,bC;
Tile *click1;
Piece *pieces[32] = {NULL};
Tile *tile[8][8] = { { NULL } };

class Border
{
public:
    Border();
    void outline(QWidget *baseWidget, int xPos, int yPos, int Pos)
    {
         QLabel *outLabel = new QLabel(baseWidget);

        if(!Pos)
            outLabel->setGeometry(xPos,yPos,552,20);        //Horizontal Borders

        else
            outLabel->setGeometry(xPos,yPos,20,512);        //Vertical Borders

                outLabel->setStyleSheet("QLabel { background-color :rgb(128, 128, 128); color : black; }");
    }
};



void chessBoard(QWidget *baseWidget, Tile *tile[8][8])
{
    int k=0,hor,ver;
    Border *border[4]={ NULL };

    //borderDisplay
    {
    border[0]->outline(baseWidget,330,105,0);
    border[1]->outline(baseWidget,330,637,0);
    border[2]->outline(baseWidget,330,125,1);
    border[2]->outline(baseWidget,862,125,1);
    }




    //Create 64 tiles (allocating memories to the objects of Tile class)
    ver=125;

    for(int i=0;i<8;i++)
    {
        hor=350;
        for(int j=0;j<8;j++)
        {
            tile[i][j] = new Tile(baseWidget);
            tile[i][j]->tileColor=(i+j)%2;
            tile[i][j]->piece=0;
            tile[i][j]->row=i;
            tile[i][j]->col=j;
            tile[i][j]->tileNum=k++;
            tile[i][j]->tileDisplay();
            tile[i][j]->x = hor;
            tile[i][j]->y = ver;
            tile[i][j]->setGeometry(hor,ver,64,64);

            hor+=64;
        }
        ver+=64;
    }

    //Add al Pawns
    hor = 350;
    for(int i = 0; i < 8; i++)
    {
            pieces[i] = new Piece(baseWidget);
            pieces[i]->setNameAndColor('P','B');
            pieces[i]->selected = false;
            pieces[i]->setPosition(hor,189);
            pieces[i]->setGeometry(hor,189,64,64);
        hor = hor + 64;
    }
    hor = 350;
    for(int i = 8; i < 16; i++)
    {
        pieces[i] = new Piece(baseWidget);
        pieces[i]->setNameAndColor('P','W');
        pieces[i]->selected = false;
        pieces[i]->setPosition(hor,509);
        pieces[i]->setGeometry(hor,509,64,64);
          hor = hor + 64;
    }

    //Add Other White Pieces
    {
        //Rook / Torres
        pieces[16] = new Piece(baseWidget);
        pieces[16]->setNameAndColor('R','W');
        pieces[16]->selected = false;
        pieces[16]->setPosition(350,573);
        pieces[16]->setGeometry(350,573,64,64);
        pieces[16]->raise();
        pieces[17] = new Piece(baseWidget);
        pieces[17]->setNameAndColor('R','W');
        pieces[17]->selected = false;
        pieces[17]->setPosition(798,573);
        pieces[17]->setGeometry(798,573,64,64);
        pieces[17]->raise();

        //Kinghts / Caballos
        pieces[18] = new Piece(baseWidget);
        pieces[18]->setNameAndColor('H','W');
        pieces[18]->selected = false;
        pieces[18]->setPosition(414,573);
        pieces[18]->setGeometry(414,573,64,64);
        pieces[18]->raise();
        pieces[19] = new Piece(baseWidget);
        pieces[19]->setNameAndColor('H','W');
        pieces[19]->selected = false;
        pieces[19]->setPosition(734,573);
        pieces[19]->setGeometry(734,573,64,64);
        pieces[19]->raise();

        //Bishops / Alfiles
        pieces[20] = new Piece(baseWidget);
        pieces[20]->setNameAndColor('B','W');
        pieces[20]->selected = false;
        pieces[20]->setPosition(478,573);
        pieces[20]->setGeometry(478,573,64,64);
        pieces[20]->raise();
        pieces[21] = new Piece(baseWidget);
        pieces[21]->setNameAndColor('B','W');
        pieces[21]->selected = false;
        pieces[21]->setPosition(670,573);
        pieces[21]->setGeometry(670,573,64,64);
        pieces[21]->raise();

        //Queen / Reina
        pieces[22] = new Piece(baseWidget);
        pieces[22]->setNameAndColor('Q','W');
        pieces[22]->selected = false;
        pieces[22]->setPosition(542,573);
        pieces[22]->setGeometry(542,573,64,64);
        pieces[22]->raise();

        //King / Rey
        pieces[23] = new Piece(baseWidget);
        pieces[23]->setNameAndColor('K','W');
        pieces[23]->selected = false;
        pieces[23]->setPosition(606,573);
        pieces[23]->setGeometry(606,573,64,64);
        pieces[23]->raise();
    }

    //Add Other Black Pieces
    {
        //Rook / Torres
        pieces[24] = new Piece(baseWidget);
        pieces[24]->setNameAndColor('R','B');
        pieces[24]->selected = false;
        pieces[24]->setPosition(350,125);
        pieces[24]->setGeometry(350,125,64,64);
        pieces[24]->raise();
        pieces[25] = new Piece(baseWidget);
        pieces[25]->setNameAndColor('R','B');
        pieces[25]->selected = false;
        pieces[25]->setPosition(798,125);
        pieces[25]->setGeometry(798,125,64,64);
        pieces[25]->raise();

        //Kinghts / Caballos
        pieces[26] = new Piece(baseWidget);
        pieces[26]->setNameAndColor('H','B');
        pieces[26]->selected = false;
        pieces[26]->setPosition(414,125);
        pieces[26]->setGeometry(414,125,64,64);
        pieces[26]->raise();
        pieces[27] = new Piece(baseWidget);
        pieces[27]->setNameAndColor('H','B');
        pieces[27]->selected = false;
        pieces[27]->setPosition(734,125);
        pieces[27]->setGeometry(734,125,64,64);
        pieces[27]->raise();

        //Bishops / Alfiles
        pieces[28] = new Piece(baseWidget);
        pieces[28]->setNameAndColor('B','B');
        pieces[28]->selected = false;
        pieces[28]->setPosition(478,125);
        pieces[28]->setGeometry(478,125,64,64);
        pieces[28]->raise();
        pieces[29] = new Piece(baseWidget);
        pieces[29]->setNameAndColor('B','B');
        pieces[29]->selected = false;
        pieces[29]->setPosition(670,125);
        pieces[29]->setGeometry(670,125,64,64);
        pieces[29]->raise();

        //Queen / Reina
        pieces[30] = new Piece(baseWidget);
        pieces[30]->setNameAndColor('Q','B');
        pieces[30]->selected = false;
        pieces[30]->setPosition(542,125);
        pieces[30]->setGeometry(542,125,64,64);
        pieces[30]->raise();

        //King / Rey
        pieces[31] = new Piece(baseWidget);
        pieces[31]->setNameAndColor('K','B');
        pieces[31]->selected = false;
        pieces[31]->setPosition(606,125);
        pieces[31]->setGeometry(606,125,64,64);
        pieces[31]->raise();
    }
    wR=7;
    wC=4;

    bR=0;
    bC=4;

}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget *myWidget = new QWidget();
    myWidget->setGeometry(30,30,1370,700);

    chessBoard(myWidget,tile);

    myWidget->show();
    return a.exec();
}

