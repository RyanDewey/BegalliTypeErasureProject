#include "bankAccount.h"

class SavingsAcc: public BankAccount{
public:

    SavingsAcc();
    void addInterest(int time);

    virtual void deposit()override;
    virtual void withdraw()override;
    virtual void print()const override;

    virtual ~SavingsAcc();
protected:
    double m_interest;

};