#include <iostream>

using namespace std;


class Point{
private:
    int num;

public:
    Point(int _num):num(_num){};

    Point operator-(const Point &ref){
        Point pos(num - ref.num);
        return pos;
    }

    void ShowNum(){
        cout << num <<endl;
    }
};


int main(void){
    Point pt1(10);
    Point pt2(3);
    Point pt3 = pt1 - pt2;
    pt3.ShowNum();

    return 0;
}