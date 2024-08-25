#include "Account.h"

using namespace std;

Account::Account(int ID, char* name, int money):accID(ID),balance(money){
    cusName = new char[strlen(name) + 1];
    strcpy(cusName, name);
}

Account::Account(Account &acc):accID(acc.accID),balance(acc.balance){
    cusName = new char[strlen(acc.cusName) + 1];
    strcpy(cusName, acc.cusName);
}

int Account::Getuid() const {
    return accID;
}

void Account::DepositMoney(int money){
    balance += money;
}

int Account::WithDrawMoney(int money){
    if(balance < money){
        cout << "you don't have enough money!" << endl;
        return 0;
    }
    balance -= money;
    return balance;
}

void Account::showInfo() const {
    cout << "계좌Id : " << accID << endl;
    cout << "이름 : " << cusName << endl;
    cout << "잔 액 : " << balance << endl;
}

Account::~Account(){
    delete []cusName;
};

