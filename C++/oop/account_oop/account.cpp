#include "account.h"


Account::Account(float start_money) :balance(start_money), transactions(0){}

void Account::Withdraw(float money){
    balance -= money;
    transactions++;
}
void Account::Deposit(float money){
    balance += money;
    transactions++;
}
float Account::GetBalance(){
    return balance;
}
void Account::EndMonthUtil(){
    std::cout << "transactions : " << transactions << " balance : "<< balance << std::endl;
    transactions = 0;
}


class MonthlyFee : public Account{
    virtual void EndMonth(void);
};
void MonthlyFee::EndMonth(void){
    Withdraw(5.00f);
    EndMonthUtil();
}


class NickleNDime : public Account{
    virtual void Withdraw(float money){
        balance -= (money+ 0.5f);
        transactions++;
    }
    virtual void EndMonth(void);
};
void NickleNDime::EndMonth(void){
    EndMonthUtil();
}

class Gambler : public Account{
    virtual void Withdraw(float money){ 
        if (RandomNum(100) <= 50){
            Account::Withdraw(2 * money);
        }
        
    }
}