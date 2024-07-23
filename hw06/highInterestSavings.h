#include "savingsAcc.h"

class HighInterestSavings: public SavingsAcc{
public:

    HighInterestSavings();
    bool checkBalance();
    virtual void deposit()override;
    virtual void withdraw()override;
    virtual void print()const override;

    virtual ~HighInterestSavings();

private:
    const double m_minBalance;
};