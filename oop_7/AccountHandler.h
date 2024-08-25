/* 
 * AccountHandler.h
 * RoughBoy
 * 08/25 21:47 0.7
 */

#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__

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

protected:
    void MakeNormalAccount(void);
    void MakeHighCreditAccount(void);
};

#endif