/* 
 * NormalAccount.h
 * RoughBoy
 * 08/25 21:47 0.7
 */

#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__

class NormalAccount : public Account{
private:
    int late;
public:
    NormalAccount(int _ID, char* _name, int _money, int _late):
        Account(_ID, _name, _money), late(_late){};

    virtual void DepositMoney(int money){
        Account::DepositMoney(money);
        cout << late << endl;;
        Account::DepositMoney(money * (late / 100.0));
    };

};

#endif