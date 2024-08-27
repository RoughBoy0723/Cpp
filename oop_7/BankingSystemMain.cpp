/* 
 * BankingSystemMain.cpp
 * RoughBoy
 * 08/25 21:47 0.7
 */

#include "BankingCommonDecl.h"
#include "AccountHandler.h"

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



