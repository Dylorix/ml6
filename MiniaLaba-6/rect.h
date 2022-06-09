#ifndef RECT_H
#define RECT_H

class QPainter;

class Rect
{
public:
    Rect();
    Rect(int x1,int x2,int y1,int y2, bool isColored = 0, int color = 0){
        this->x1 = (x1<x2 ? x1 : x2);
        this->y1 = (y1<y2 ? y1 : y2);
        this->x2 = (x1>x2 ? x1 : x2);
        this->y2 = (y1>y2 ? y1 : y2);
        this->isColored = isColored;
        this->color = color;
    }
    bool contains(int x, int y){
        if(x<this->x1) return false;
        else if(x>this->x2) return false;
        else if(y<this->y1) return false;
        else if(y>this->y2) return false;
        else return true;
    }
    int getX1() const;
    void setX1(int newX1);

    int getX2() const;
    void setX2(int newX2);

    int getY1() const;
    void setY1(int newY1);

    int getY2() const;
    void setY2(int newY2);

    virtual void draw(QPainter *painter);
    virtual void Colordraw(QPainter *painter);

    bool getIsColored() const;
    void setIsColored(bool newIsColored);

private:
    int x1,x2,y1,y2;
    bool isColored; //Красить ли прямоугольник?
    int color; //В какой цвет красить?
    int c1,c2,c3,c4; //Это для насторойки цвета
};

#endif // RECT_H
