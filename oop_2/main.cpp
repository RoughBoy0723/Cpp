#include "../bits/stdc++.h"

using namespace std;

void show_menu(void);
void MakeAccount(void);
int DepositMoney(void);
int WithDrawMoney(void);
void ShowInfo(void);

enum {MAKE =1 , DEPOSIT, WITHDRAW, INQUIRE, EXIT};

const int NAME_LEN = 20;




class Account{
private:    
    int accID;
    char* cusName;
    int balance;

public:

    Account(int ID, char* name, int money):accID(ID),balance(money){
        cusName = new char[strlen(name) + 1];
        strcpy(cusName, name);
    }

    int Getuid(){
        return accID;
    }

    void DepositMoney(int money){
        balance += money;
    }

    int WithDrawMoney(int money){
        if(balance < money){
            cout << "you don't have enough money!" << endl;
            return 0;
        }else{
            balance -= money;
        }
        return balance;
    }

    void showInfo(){
        cout << "계좌Id : " << this->accID << endl;
        cout << "이름 : " << this->cusName << endl;
        cout << "잔 액 : " << this->balance << endl;
    }

    ~Account(){
        delete []cusName;
    }
};

int accNum = 0;
Account * account[100];

int main(void){
    int choice;
    while(1){
        show_menu();
        cin >> choice;
        switch(choice){
            case MAKE:
                MakeAccount();
                break;
            
            case DEPOSIT:
                DepositMoney();
                break;

            case WITHDRAW:
                WithDrawMoney();
                break;
            
            case INQUIRE:
                ShowInfo();
                break;
            
            case EXIT:
                for(int i = 0 ; i < accNum ; i++){
                    delete account[i];
                }
                return 0;
            
            default :
                cout << "올바르지 않은 입력입니다."<< endl;
        }
    }
    return 0;
}

void show_menu(){
        cout << "-----Menu-----" <<endl;
        cout << "1. 계좌개설" <<endl;
        cout << "2. 입 금" <<endl;
        cout << "3. 출 금" <<endl;
        cout << "4. 계좌정보 전체 출력" <<endl;
        cout << "5. 프로그램 종료" <<endl;
        cout << "선택 : ";
}

void MakeAccount(){
    char name[NAME_LEN];
    int id, money;

    cout << "[계좌개설]" << endl;
    cout << "계좌ID: ";     cin >> id;
    cout << "이 름: ";      cin >> name;
    cout << "입금액 : ";    cin >> money;

    account[accNum++] = new Account(id,name,money);
}

int DepositMoney(){
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

int WithDrawMoney(){
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

void ShowInfo(){
    for(int i = 0; i < accNum ; i++){
        account[i]->showInfo();
        cout<<endl;
    }
}