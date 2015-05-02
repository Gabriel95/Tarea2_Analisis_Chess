#ifndef TILE_H
#define TILE_H
#include <QLabel>
#include <QDebug>
#include <piece.h>
class Tile: public QLabel
{
public:


    int tileColor,piece,pieceColor,row,col,tileNum,x,y;
    char pieceName;


    Tile(QWidget* pParent=0, Qt::WindowFlags f=0) : QLabel(pParent, f) {};
    Tile(const QString& text, QWidget* pParent = 0, Qt::WindowFlags f = 0) : QLabel(text, pParent, f){};


    void mousePressEvent(QMouseEvent *event);
    void tileDisplay();
    void movePiece();
};

#endif // TILE_H
