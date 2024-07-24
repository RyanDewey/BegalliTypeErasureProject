#include "checkingAcc.h"

class NoServiceChargeChk: public CheckingAcc{
    public:

    NoServiceChargeChk();
    void addInterest(int time);
    bool checkBalance();

    virtual void deposit()override;
    virtual void withdraw()override;
    virtual void print()const override;
    virtual void writeCheck()override;

    double getMinBalance() const;
    double getInterestRate() const;
    
    void setInterestRate(double);
    void setMinBalance(double);

    virtual~NoServiceChargeChk();

    protected:
    double m_interest;
    double m_minBalance;
};

class HighInterestChk: public CheckingAcc{
    public:

    HighInterestChk();

    virtual void deposit()override;
    virtual void withdraw()override;
    virtual void print()const override;
    virtual void writeCheck()override;

    virtual~HighInterestChk();

    protected:
    double m_interest;
    double m_minBalance;
};

//----------

class CheckingCompat {
  public:
    virtual void addInterest(int time) {
        // define here
        return;
    }
    virtual ~CheckingCompat() {}
};

template<typename T>
class CheckingAdapter: public CheckingCompat {
  public:
    CheckingAdapter(const T& obj) : obj_(obj) {}
    void addInterest(int time) override {
        std::ofstream out("statements.txt", std::ios::app);
        for(int i = 0; i < time; i++){
            m_balance *= (m_interest + 1);
            std::cout << "BALANCE FOR MONTH[" << i+1 << "]: " << m_balance << '\n';
            out << "BALANCE FOR MONTH[" << i+1 << "]: " << m_balance << '\n';
        }
        out.close();
    }
    ~CheckingAdapter() {}
  private:
    const T& obj_;
};
  
int main() {
  
  CheckingCompat *t[] = {new CheckingAdapter(NoServiceChargeChk()),new CheckingAdapter(HighInterestChk())};
  for(auto& x: t){
    x->addInterest(1);
  }
  return 0;
}
