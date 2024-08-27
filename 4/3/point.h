#include <iostream>

using namespace std;

class Point{
private:
    int xpos;
    int ypos;

public:
    Point(int x, int y)
    {
        xpos = x;
        ypos = y;
    }
    void showPointInfo() const
    {
        cout << "[" <<xpos << ", "<< ypos << "]"<<endl;
    }
};

class Circle{
private:
    Point pnt;
    int rad;
public:
    Circle(int x, int y, int r): pnt(x,y)
    {
        rad = r;
    }
    void ShowCircleInfo(){
        cout << "radius: " << rad <<endl;
        pnt.showPointInfo();
    }
};

class Ring{
private:
    Circle outcircle;
    Circle incircle;
public:
    Ring(int x1, int y1, int r1, int x2, int y2, int r2): outcircle(x1,y1,r1), incircle(x2,y2,r2)
    {}
    void ShowRingInfo(){
        cout << "Inner Circle Info..." <<endl;
        outcircle.ShowCircleInfo();
        cout << "Outter Circle Info..." <<endl;
        incircle.ShowCircleInfo();
    }
};
