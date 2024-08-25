#ifndef AccountHandler
#define AccountHandler

#include <iostream>
#include <cstring>
#include "Account.h"

class AccountHandler{
private:
    Account * account[100];
    int accNum;
    
public:
    AccountHandler();
    void ShowMenu(void) const;
    void MakeAccount(void);
    int DepositMoney(void);
    int WithDrawMoney(void);
    void ShowInfo(void);
    ~AccountHandler();
};

#endif