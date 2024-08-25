#ifndef _Account
#define _Account

#include <iostream>
#include <cstring>

class Account{
private:    
    int accID;
    char* cusName;
    int balance;
    
public:
    Account(int ID, char* name, int money);
    Account(Account &acc);

    int Getuid() const;
    void DepositMoney(int money);
    int WithDrawMoney(int money);
    void showInfo() const;
    ~Account();
};
#endif