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


    virtual ~CheckingAcc();
};

#endif