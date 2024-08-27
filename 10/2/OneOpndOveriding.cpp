#include <iostream>

using namespace std;

class Point{
private:
    int xpos;
    int ypos;

public:
    Point(int x = 0, int y = 0): xpos(x), ypos(y){}

    void ShowPoint(){
        cout << "[" << xpos << ',' << ypos << "]" << endl;
    }

    Point operator-(){
        return Point(-xpos, -ypos);
    }
    friend Point operator~(Point &ref);
};

Point operator~(Point &ref){
    return Point(~ref.xpos, ~ref.ypos);
} 

int main(void){
    Point pt1(10,5);
    pt1.ShowPoint();
    
    Point pt2 = -pt1;
    pt2.ShowPoint();

    Point pt3 = ~pt2;
    pt3.ShowPoint();

    return 0;
}