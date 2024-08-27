/* 
 * HighCreditAccount.h
 * RoughBoy
 * 08/25 21:47 0.7
 */

#ifndef __HIGH_CREDIT_ACCOUNT_H__
#define __HIGH_CREDIT_ACCOUNT_H__

class HighCreditAccount : public NormalAccount{
private:
    int creditlate;
public:
    HighCreditAccount(int _ID, char* _name, int _money, int _late, int _creditlate):
        NormalAccount(_ID, _name, _money, _late), creditlate(_creditlate){};

    virtual void DepositMoney(int money){
        NormalAccount::DepositMoney(money);
        Account::DepositMoney(money * (creditlate / 100.0));
    };
};

#endif