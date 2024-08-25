#include <cstring>
#include <iostream>

enum {MAKE =1 , DEPOSIT, WITHDRAW, INQUIRE, EXIT};
enum {Normal = 1, HighCredit};
enum {A = 7, B = 4, C = 2};

const int NAME_LEN = 20;

using namespace std;


/*==========Account==========*/
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


/*==========Normal Account==========*/
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

/*==========High Credit Account==========*/
class HighCreditAccount : public NormalAccount{
private:
    int creditlate;
public:
    HighCreditAccount(int _ID, char* _name, int _money, int _late, int _creditlate):
        NormalAccount(_ID, _name, _money, _late), creditlate(_creditlate){};

    virtual void DepositMoney(int money){
        NormalAccount::DepositMoney(money);
        cout << creditlate << endl;;
        Account::DepositMoney(money * (creditlate / 100.0));
    };
};

/*=================Account Handler==================*/
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


AccountHandler::AccountHandler():accNum(0){}

void AccountHandler::ShowMenu() const {
        cout << "-----Menu-----" <<endl;
        cout << "1. 계좌개설" <<endl;
        cout << "2. 입 금" <<endl;
        cout << "3. 출 금" <<endl;
        cout << "4. 계좌정보 전체 출력" <<endl;
        cout << "5. 프로그램 종료" <<endl;
        cout << "선택 : ";
}

void AccountHandler::MakeAccount(){
    int kind;
    cout << "[계좌종류선택]" << endl;
    cout << "1.보통예금계좌" << endl;
    cout << "2.신용신뢰계좌" << endl;
    cout << "선택: ";     cin >> kind;
    switch(kind){
        case Normal :
            MakeNormalAccount();
            break;

        case HighCredit:
            MakeHighCreditAccount();
            break;
    }
}

void AccountHandler::MakeNormalAccount(){
    char name[NAME_LEN];
    int id, money;
    int late;
    cout << "[계좌 종류선택 개설]" << endl;
    cout << "계좌ID: ";     cin >> id;
    cout << "이 름: ";      cin >> name;
    cout << "입금액 : ";    cin >> money;
    cout << "이자율 :";     cin >> late;
    account[accNum++] = new NormalAccount(id,name,money,late);
}

void AccountHandler::MakeHighCreditAccount(){
    char name[NAME_LEN];
    int id, money;
    int late, creditlate;
    cout << "[계좌 종류선택 개설]" << endl;
    cout << "계좌ID: ";     cin >> id;
    cout << "이 름: ";      cin >> name;
    cout << "입금액: ";    cin >> money;
    cout << "이자율: ";     cin >> late;
    cout << "신용등급(1toA, 2toB, 3toC): "; cin >> creditlate;
    switch (creditlate)
    {
    case 1 : 
        account[accNum++] = new HighCreditAccount(id,name,money,late,A);
        break;

    case 2 :
        account[accNum++] = new HighCreditAccount(id,name,money,late,B);
        break;

    case 3 :
        account[accNum++] = new HighCreditAccount(id,name,money,late,C);
        break;    
    }
}
int AccountHandler::DepositMoney(){
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

int AccountHandler::WithDrawMoney(){
    int id, money;
    cout << "[출    금]" << endl;
    cout << "계좌ID: ";     cin >> id;
    cout << "출금액 : ";    cin >> money;
    for(int k = 0 ; k < accNum ; k++ ){
        if(account[k]->Getuid() == id){
            if(account[k]->WithDrawMoney(money) == 0){
                cout << "잔액 부족" << endl<<endl;
                return 0;
            }
            cout << "출금완료" << endl<<endl;
            return 0;
        }
    }
    cout << "없는 아이디 입니다." <<endl<<endl;
    return 0;
}

void AccountHandler::ShowInfo(){
    for(int i = 0; i < accNum ; i++){
        account[i]->showInfo();
        cout<<endl;
    }
}

AccountHandler::~AccountHandler(){
    for(int i = 0 ; i<accNum;i++){
        delete account[i];
    }
}

/*==========Main==========*/
int main(void){
    AccountHandler manager;
    int choice;
    while(1){
        manager.ShowMenu();
        cin >> choice;
        switch(choice){
            case MAKE:
                manager.MakeAccount();
                break;
            
            case DEPOSIT:
                manager.DepositMoney();
                break;

            case WITHDRAW:
                manager.WithDrawMoney();
                break;
            
            case INQUIRE:
                manager.ShowInfo();
                break;
            
            case EXIT:
                return 0;
            
            default :
                cout << "올바르지 않은 입력입니다."<< endl;
        }
    }
    return 0;
}



