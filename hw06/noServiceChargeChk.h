#ifndef CHECKINGACC_H
#define CHECKINGACC_H

#include <memory>
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

    /*int test() {
      //CheckingAdapter test1 = new CheckingAdapter(NoServiceChargeChk());
      //CheckingAdapter test2 = new CheckingAdapter(NoServiceChargeChk());

      CheckingCompat *t[] = {new CheckingAdapter(NoServiceChargeChk()),new CheckingAdapter(HighInterestChk())};
      for(auto& x: t){
        x->addInterest(1);
    }*/
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

/*class CheckingCompat {
  public:
    virtual void addInterest(int time) {
        //define
        return;
    }
    virtual ~CheckingCompat() {}
};*/

/*template<typename T>
class CheckingAdapter: public CheckingCompat {
  public:
    CheckingAdapter(T&& obj) : obj_(std::move(obj)) {}
    void addInterest(int time) override {
        std::ofstream out("statements.txt", std::ios::app);
        for(int i = 0; i < time; i++){
            obj_.setBalance(obj_.getBalance() * (obj_.getInterestRate() + 1));
            std::cout << "BALANCE FOR MONTH[" << i+1 << "]: " << obj_.getBalance() << '\n';
            out << "BALANCE FOR MONTH[" << i+1 << "]: " << obj_->getBalance() << '\n';
        }
        out.close();
    }
    ~CheckingAdapter() {}
  private:
    T&& obj_;
};*/

class CheckingCompat {
 public:
  template<typename T>
  CheckingCompat(T& obj):m_account(std::make_shared<CheckingAdapter<T>>(std::move(obj))) {}
    virtual void setBalance(double amt) {
      m_account->setBalance(amt);
    }
    virtual double getBalance() {
      m_account->getBalance();
    }
    virtual void getInterestRate(double amt) {
      m_account->getInterestRate(amt);
    }
    virtual void calcInterest(int months) {
      m_account->calcInterest(months);
    }
  ~CheckingCompat() {}
 private:
  std::shared_ptr<CheckingAcc>m_account;
  /*class CheckingBase {
    public:
      void setBalance(double);
      virtual void calcInterest(int) = 0;
      virtual std::string motion() const {
          return "thing: roll";
      }*/
  };
  template<typename T>
  class CheckingAdapter: public CheckingAcc {
    public:
      CheckingAdapter(T& obj) : obj_(std::move(obj)) {}
      virtual void setBalance(double amt) override {
        obj_.setBalance(amt);
      }
      virtual double getBalance() override {
        obj_.getBalance();
      }
      virtual void getInterestRate(double amt) {
        obj_.getInterestRate(amt);
      }
      virtual void calcInterest(int months) {
        obj_.calcInterest(months);
      }

    private:
      T& obj_;
};


//int test() {
/*CheckingAdapter test1 = new CheckingAdapter(NoServiceChargeChk());
CheckingAdapter test2 = new CheckingAdapter(NoServiceChargeChk());

CheckingCompat *t[] = {new CheckingAdapter(NoServiceChargeChk()),new CheckingAdapter(HighInterestChk())};
for(auto& x: t){
  x->addInterest(1);
}*/

#endif
