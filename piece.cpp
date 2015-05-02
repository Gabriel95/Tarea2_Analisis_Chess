#include "piece.h"
#include "validation.h"

extern Piece *pieces[32];

void Piece::setNameAndColor(char name, char color)
{
    this->name = name;
    this->color = color;
    if(color == 'W')
    {
        switch(this->name)
        {
        case 'P': this->setPixmap(QPixmap(":/Images/pawn_white.svg"));
              break;
         case 'R': this->setPixmap(QPixmap(":/Images/rook_white.svg"));
              break;
          case 'H': this->setPixmap(QPixmap(":/Images/knight_white.svg"));
              break;
            case 'K': this->setPixmap(QPixmap(":/Images/king_white.svg"));
              break;
             case 'Q': this->setPixmap(QPixmap(":/Images/queen_white.svg"));
              break;
               case 'B': this->setPixmap(QPixmap(":/Images/bishop_white.svg"));
              break;
    }
    }else
    {
        switch(this->name)
        {
        case 'P': this->setPixmap(QPixmap(":/Images/pawn_black.svg"));
                         break;
               case 'R': this->setPixmap(QPixmap(":/Images/rook_black.svg"));
                         break;
               case 'H': this->setPixmap(QPixmap(":/Images/knight_black.svg"));
                         break;
               case 'K': this->setPixmap(QPixmap(":/Images/king_black.svg"));
                         break;
               case 'Q': this->setPixmap(QPixmap(":/Images/queen_black.svg"));
                         break;
               case 'B': this->setPixmap(QPixmap(":/Images/bishop_black.svg"));
                         break;
        }
    }
this->setStyleSheet("QLabel {background-color: rgba(0,0,0,0%)}:hover{background-color: rgb(170,85,127);}");
}

void Piece::setPosition(int row, int column)
{
    this->row = row;
    this->column = column;
}

void Piece::select()
{
    for(int i =0; i < 32; i++)
    {
        if(pieces[i]->selected)
        {
           pieces[i]->deSelect();
        }
    }
    this->selected = true;
    this->setStyleSheet("QLabel {background-color: green;}");


}

void Piece::deSelect()
{
    this->selected = false;
    this->setStyleSheet("QLabel {background-color: rgba(0,0,0,0%)}");
}

void Piece::mousePressEvent(QMouseEvent *event)
{
    if(!this->selected)
    select();
    else
    deSelect();
}
