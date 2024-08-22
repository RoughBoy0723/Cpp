#include "../bits/stdc++.h"

using namespace std;

void show_menu(void);
void MakeAccount(void);
void DepositMoney(void);
void WithDrawMoney(void);
void ShowInfo(void);


enum {MAKE =1 , DEPOSIT, WITHDRAW, INQUIRE, EXIT};


typedef struct{
    int ID;
    string name;
    int money;
}Account;

Account account[100];
int accNum = 0;

int main(){
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
                return 0;
                break;
            
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

int acc_num = 0;
void MakeAccount(){
    int id;
    cout << "[계좌개설]" << endl;
    cout << "계좌ID: ";
    cin >> id;
    account[acc_num].ID = id;
    int k;
    bool a = false;

    for( k = 0 ; k < acc_num ; k++ ){
        if(account[k].ID == id){
            a = true;
            break;
        }
    }
    if(a){
        cout << "이미 존재하는 ID 입니다."<<endl;
        return;    
    }
    cout << "이 름: ";
    cin >> account[acc_num].name;
    cout << "입금액 : ";
    cin >> account[acc_num].money;
    acc_num++;
}

void DepositMoney(){
    int id;
    int money;
    bool a = false;
    cout << "[입    금]" << endl;
    cout << "계좌ID: ";
    cin >> id;
    int k;
    for( k = 0 ; k < acc_num ; k++ ){
        if(account[k].ID == id){
            a = true;
            break;
        }
    }
    
    if(a){
        cout << "입금액 : ";
        cin >> money;
        account[k].money += money;
        cout << "입금완료" << endl;
    }else{
        cout << "존재하지 않는 아이디 입니다." << endl;
        return;
    }
}

void WithDrawMoney(){
    int id;
    int money;
    bool a = false;
    cout << "[출    금]" << endl;
    cout << "계좌ID: ";
    cin >> id;
    int k;
    for( k = 0 ; k < acc_num ; k++ ){
        if(account[k].ID == id){
            a = true;
            break;
        }
    }
    
    if(a){
        cout << "출금액 : ";
        cin >> money;
        if(account[k].money < money){
            cout << "출금하려는 금액이 잔액보다 큽니다." << endl;
            return;
        }
        account[k].money -= money;
        cout << "출금완료" << endl;
    }else{
        cout << "없는 아이디 입니다." <<endl;
    }
}

void ShowInfo(){
    if(acc_num==0){
        cout << "출력할 계좌가 존재하지 않습니다." << endl;
        return;
    }
    for(int i = 0 ; i < acc_num ; i++){
        cout << "계좌Id : " << account[i].ID << endl;
        cout << "이름 : " << account[i].name << endl;
        cout << "잔 액 : " << account[i].money << endl;
    }
}