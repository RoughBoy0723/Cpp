#include <iostream>

using namespace std;


class Point{
private:
    int xpos;
    int ypos;

public:
    Point(int _xpos, int _ypos):xpos(_xpos), ypos(_ypos){};
    
    void ShowNum(){
        cout << '['<< xpos <<','<< ypos <<']' <<endl;
    }
    
    friend Point operator-(const Point &ref1, const Point &ref2);
    friend bool operator==(const Point &ref1, const Point &ref2);
    friend bool operator!=(const Point &ref1, const Point &ref2);
    Point operator+=(const Point &ref){
        this->xpos += ref.xpos;
        this->ypos += ref.ypos;
        return *this;
    };
    Point operator-=(const Point &ref){
        this->xpos -= ref.xpos;
        this->ypos -= ref.ypos;
        return *this;
    };
    
};

Point operator-(const Point &ref1, const Point &ref2){
    Point pos(ref1.xpos - ref2.xpos, ref1.ypos - ref2.ypos );
    return pos;
}

bool operator==(const Point &ref1,const Point &ref2){
    if(ref1.xpos == ref2.xpos && ref1.ypos == ref2.ypos){
        return true;
    }
    return false;
}

bool operator!=(const Point &ref1,const Point &ref2){
    return !(ref1==ref2);
}

int main(void){
    Point pt1(12, 21);
    Point pt2(0, 20);
    Point pt3 = pt1 - pt2;
    pt3.ShowNum();
    Point pt4(1, 12); 
    (pt4 += pt1).ShowNum();
    Point pt5(20, 10); 
    (pt5 -= pt2).ShowNum();

    Point pt6(12,21);
    if(pt6 == pt1){
        cout << "1: pt6 == pt1\n";
    }else{
        cout << "1: pt6 != pt1\n";
    }



    if(pt6 != pt2){
        cout << "2: pt6 != pt1\n";
    }else{
        cout << "2: pt6 == pt1\n";
    }

    
    return 0;
}