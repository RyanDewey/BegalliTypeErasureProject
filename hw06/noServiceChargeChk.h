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

    bool checkBalance(){
        if (m_balance < m_minBalance) {
        return false;
    }
    return true;
    };


    virtual void deposit()override;
    virtual void withdraw()override;
    virtual void print()const override;
    virtual void writeCheck()override;

    virtual~HighInterestChk();

    double getInterestRate() const{
        return m_interest;
    }

    double getMinBalance() const{
        return m_minBalance;
    }

    void setInterestRate(double rate){
        m_interest = rate;
    }

    void setMinBalance(double amt){
        m_minBalance = amt;
    }

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
    CheckingAdapter(T& obj) : obj_(obj) {}
    void addInterest(int time) override {
        std::ofstream out("statements.txt", std::ios::app);
        for(int i = 0; i < time; i++){
            obj_.setBalance(obj_.getBalance() * (obj_.getInterestRate() + 1));
            std::cout << "BALANCE FOR MONTH[" << i+1 << "]: " << obj_.getBalance() << '\n';
            out << "BALANCE FOR MONTH[" << i+1 << "]: " << obj_.getBalance() << '\n';
        }
        out.close();
    }
    ~CheckingAdapter() {}
  private:
    T& obj_;
};
  
int test() {
  CheckingAdapter test1 = new CheckingAdapter(NoServiceChargeChk());
  CheckingAdapter test2 = new CheckingAdapter(NoServiceChargeChk());

  CheckingCompat *t[] = {new CheckingAdapter(NoServiceChargeChk()),new CheckingAdapter(HighInterestChk())};
  for(auto& x: t){
    x->addInterest(1);
  }
  return 0;
}
