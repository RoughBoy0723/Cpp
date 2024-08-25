#include "Account.h"
#include "AccountHandler.h"

enum {MAKE =1 , DEPOSIT, WITHDRAW, INQUIRE, EXIT};

const int NAME_LEN = 20;

using namespace std;

int main(void){
    AccountHandler manager;
    int choice;
    while(1){
        manager.ShowMenu();
        cin >> choice;
        switch(choice){
            case MAKE:
                manager.MakeAccount();
                break;
            
            case DEPOSIT:
                manager.DepositMoney();
                break;

            case WITHDRAW:
                manager.WithDrawMoney();
                break;
            
            case INQUIRE:
                manager.ShowInfo();
                break;
            
            case EXIT:
                return 0;
            
            default :
                cout << "올바르지 않은 입력입니다."<< endl;
        }
    }
    return 0;
}



