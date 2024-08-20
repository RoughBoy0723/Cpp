#include <iostream>

class Printer{
    std::string buffer;
    
    public:
        void SetString( std::string buf) { buffer = buf; }
        void ShowString(){ std::cout << buffer << std::endl; }

};