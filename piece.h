#ifndef PIECE_H
#define PIECE_H
#include <QLabel>
#include <QDebug>

class Piece: public QLabel
{
public:

    //Fields
    int tileColor,piece,pieceColor,row,column,tileNum;
    char name, color;
    bool selected;

    //Constructors
    Piece(QWidget* pParent=0, Qt::WindowFlags f=0) : QLabel(pParent, f) {};
    Piece(const QString& text, QWidget* pParent = 0, Qt::WindowFlags f = 0) : QLabel(text, pParent, f){};

    //Methods
    void setNameAndColor(char name, char color);
    void setPosition(int row, int column);
    void select();
    void deSelect();
    void mousePressEvent(QMouseEvent *event);

};

#endif // TILE_H
