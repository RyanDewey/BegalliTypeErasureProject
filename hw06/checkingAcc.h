#ifndef _CHKACC_
#define _CHKACC_
#include "bankAccount.h"

class CheckingAcc: public BankAccount{
public:
    CheckingAcc();

    virtual void deposit()override;
    virtual void withdraw()override;
    virtual void print()const override;
    virtual void writeCheck() = 0;
    virtual void setBalance(double) = 0;
    virtual double getBalance() = 0;
    virtual void getInterestRate(double) = 0;
    virtual void calcInterest(int) = 0;


    virtual ~CheckingAcc();
};

#endif
