/* 
 * Account.h
 * RoughBoy
 * 08/25 21:47 0.7
 */

#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

class Account{
private:    
    int accID;
    char* cusName;
    int balance;
    int kind;
public:
    Account(int ID, char* name, int money);
    Account(Account &acc);

    int GetBalance() const;
    int Getuid() const;
    virtual void DepositMoney(int money);
    int WithDrawMoney(int money);
    void showInfo() const;
    ~Account();
};

#endif