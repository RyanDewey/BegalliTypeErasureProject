#include "checkingAcc.h"

class ServiceChargeChecking: public CheckingAcc{
public:
    ServiceChargeChecking();
    void monthlyServiceFee(int time);
    virtual void deposit()override;
    virtual void withdraw()override;
    virtual void print()const override;
    virtual void writeCheck()override;

    virtual~ServiceChargeChecking();


private:
    const double m_serviceCharge;
    const int m_maxChecks;
    int m_numChecks;
};