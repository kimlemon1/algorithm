#pragma once
#include <iostream>
#include <stdlib.h>

class Account{
    protected:
        float balance;
        int transactions;
        void EndMonthUtil(void);

    public:
        Account(float start_money);

        virtual void Withdraw(float money);
        virtual void Deposit(float money);
        virtual float GetBalance();
        virtual void EndMonth(void) = NULL;


};