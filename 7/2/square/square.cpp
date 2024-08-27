#include <iostream>

using namespace std;

class Rectangle 
{
private:
    int width; 
    int height;
public:
    Rectangle(int _width, int _height): width(_width),height(_height)
    {};
    
    void ShowAreaInfo(){
        cout << "면적:" << width * height << endl;
    }
    ~Rectangle(){};
};

class Square: public Rectangle
{
private:
    int length;
public:
    Square(int _length):Rectangle(_length, _length){};
    ~Square(){};
};

int main(int argc, char const *argv[])
{
    Rectangle rec(4,3);
    rec.ShowAreaInfo();

    Square sqr(7);
    sqr.ShowAreaInfo();
    return 0;
}
