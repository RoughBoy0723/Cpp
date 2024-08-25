#include "AccountHandler.h"

using namespace std;

AccountHandler::AccountHandler():accNum(0){}

const void AccountHandler::ShowMenu() const {
        cout << "-----Menu-----" <<endl;
        cout << "1. 계좌개설" <<endl;
        cout << "2. 입 금" <<endl;
        cout << "3. 출 금" <<endl;
        cout << "4. 계좌정보 전체 출력" <<endl;
        cout << "5. 프로그램 종료" <<endl;
        cout << "선택 : ";
}

void AccountHandler::MakeAccount(){
    char name[NAME_LEN];
    int id, money;

    cout << "[계좌개설]" << endl;
    cout << "계좌ID: ";     cin >> id;
    cout << "이 름: ";      cin >> name;
    cout << "입금액 : ";    cin >> money;

    account[accNum++] = new Account(id,name,money);
}

int AccountHandler::DepositMoney(){
    int id;
    int money;
    bool a = false;
    cout << "[입    금]" << endl;
    cout << "계좌ID: ";
    cin >> id;
    int k;
    for( k = 0 ; k < accNum ; k++ ){
        if(account[k]->Getuid() == id){
            cout << "입금액 : ";
            cin >> money;
            account[k]->DepositMoney(money);
            cout << "입금완료" << endl;
            return 0;
        }
    }
    cout << "존재하지 않는 아이디 입니다." << endl << endl;
    return 0;

}

int AccountHandler::WithDrawMoney(){
    int id, money;
    cout << "[출    금]" << endl;
    cout << "계좌ID: ";     cin >> id;
    cout << "출금액 : ";    cin >> money;
    for(int k = 0 ; k < accNum ; k++ ){
        if(account[k]->Getuid() == id){
            if(account[k]->WithDrawMoney(money) == 0){
                cout << "잔액 부족" <<endl <<endl;
            }
            cout << "출금완료" << endl<<endl;
            return 0;
        }
    }
    cout << "없는 아이디 입니다." <<endl<<endl;
    return 0;
}

void AccountHandler::ShowInfo(){
    for(int i = 0; i < accNum ; i++){
        account[i]->showInfo();
        cout<<endl;
    }
}

AccountHandler::~AccountHandler(){
    for(int i = 0 ; i<accNum;i++){
        delete account[i];
    }
}