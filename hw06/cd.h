#include "bankAccount.h"

class CD: public BankAccount {
public:
    CD();

    void addInterest(int time);
    void setMaturity();
    void setMonth(const int month);
    virtual void deposit();
    virtual void withdraw();
    virtual void print()const;

    virtual ~CD();

private:
    int m_maturityMonths;
    int m_currMonth;
    double m_interest;
    double m_compound;
    const double m_withdrawPenalty;
};