#include "noServiceChargeChk.h"

class HighInterestChk: public NoServiceChargeChk{
    public:

    HighInterestChk();

    virtual void deposit()override;
    virtual void withdraw()override;
    virtual void print()const override;
    virtual void writeCheck()override;

    virtual~HighInterestChk();
};
