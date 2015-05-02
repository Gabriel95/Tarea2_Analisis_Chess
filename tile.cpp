#include "tile.h"
#include "validation.h"

extern int count,turn;
extern QWidget *myWidget;
extern Tile *click1;
extern Tile *tile[8][8];
extern Piece *pieces[32];


void Tile::mousePressEvent(QMouseEvent *event)
{
    movePiece();
}

void Tile::tileDisplay()
{

    if(this->tileColor)
        this->setStyleSheet("QLabel {background-color: rgb(105, 105, 105 );}:hover{background-color: rgb(170,85,127);}");
    else
        this->setStyleSheet("QLabel {background-color: rgb(248, 248, 255);}:hover{background-color: rgb(170,95,127);}");
}

void Tile::movePiece()
{
    for(int i =0; i < 32; i++)
    {
        if(pieces[i]->selected)
        {
           pieces[i]->row = this->x;
           pieces[i]->column = this->y;
           pieces[i]->setGeometry(this->x, this->y, 64, 64);
           pieces[i]->deSelect();
        }
    }
}


