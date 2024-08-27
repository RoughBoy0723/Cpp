/* 
 * Account.cpp
 * RoughBoy
 * 08/25 21:47 0.7
 */

#include "Account.h"
#include "BankingCommonDecl.h"

Account::Account(int ID, char* name, int money):accID(ID),balance(money){
    cusName = new char[strlen(name) + 1];
    strcpy(cusName, name);
}

Account::Account(Account &acc):accID(acc.accID),balance(acc.balance){
    cusName = new char[strlen(acc.cusName) + 1];
    strcpy(cusName, acc.cusName);
}

int Account::GetBalance() const {
    return balance;
}

int Account::Getuid() const {
    return accID;
}

void Account::DepositMoney(int money){
    balance += money;
}

int Account::WithDrawMoney(int money){
    if(balance < money){
        return 0;
    }
    balance -= money;
    cout << "통장 잔액: "<< balance <<endl <<endl;
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