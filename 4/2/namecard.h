#include <iostream>
#include <cstring>

using namespace std;

namespace COMP_POS{
    enum{
        CLERK,
        SENIOR,
        ASSIST,
        MANAGER
    };
}

class NameCard{
private:
    char *name;
    char *componey;
    char *phonenum;
    int pos;

public:
    NameCard(char *_name, char *_componey, char* _phonenum, int _pos){
        name = new char[strlen(_name)];
        strcpy(name,_name);

        componey = new char[strlen(_componey)];
        strcpy(componey,_componey);

        phonenum = new char[strlen(_phonenum)];
        strcpy(phonenum,_phonenum);
        pos = _pos;
    };
    ~NameCard(){
        delete []name;
        delete []componey;
        delete []phonenum;
    }
    char* GetPosition() const {
        switch(pos) {
            case COMP_POS::CLERK: return "Clerk";
            case COMP_POS::SENIOR: return "Senior";
            case COMP_POS::ASSIST: return "Assistant";
            case COMP_POS::MANAGER: return "Manager";
        }
    }
    void ShowNameCardInfo() const {
        cout << "이름: " << name << endl;
        cout << "회사: " << componey << endl;
        cout << "전화번호: " << phonenum << endl;
        cout << "직급: " << GetPosition() << endl<<endl;
    }
};