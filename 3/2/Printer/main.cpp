#include "printer.h"

int main(){
    Printer pnt;
    
    pnt.SetString("Hello world");
    pnt.ShowString();

    pnt.SetString("I love C++");
    pnt.ShowString();
    return 0;
}