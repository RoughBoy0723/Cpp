#include <iostream>
#include <cstring>
#include <string.h>

using namespace std;

class MyFriendInfo{
private:
    char *name;
    int age;

public:
    MyFriendInfo(char *_name, int _age):age(_age){
        cout << "create []name\n";

        name = new char[strlen(_name)+1];
        strcpy(name, _name);       
    }

    void ShowMyFriendInfo(){
        cout << "이름: " << name << endl;
        cout << "나이: " << age << endl;
    }

    ~MyFriendInfo(){
        cout << "delete []name\n";
        delete []name;
    }
};

class MyFriendDetailInfo : public MyFriendInfo{
private:
    char *addr;
    char *phone;

public:
    MyFriendDetailInfo(char *_name, int _age, char *_addr, char *_phone): MyFriendInfo(_name, _age){
        cout << "create []addr\ncreate []phone\n";

        addr = new char[strlen(_addr)+1];
        strcpy(addr, _addr);
        phone = new char[strlen(_phone)+1];
        strcpy(phone, _phone);
    }

    void ShowMyFriendDetailInfo(){
        ShowMyFriendInfo();
        cout << "주소: " << addr << endl;
        cout << "전화: " << phone << endl;
    }

    ~MyFriendDetailInfo(){
        cout << "delete []addr\ndelete []phone\n";
        delete []addr;
        delete []phone;
    }
};


int main(void){
    MyFriendDetailInfo MFDI("오원영", 26, "가산", "010-****-****");
    MFDI.ShowMyFriendDetailInfo();
    
    return 0;
}