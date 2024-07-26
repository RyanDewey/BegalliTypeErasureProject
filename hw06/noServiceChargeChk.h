#ifndef CHECKINGACC_H
#define CHECKINGACC_H

#include <memory>
#include "checkingAcc.h"

class NoServiceChargeChk: public CheckingAcc{
    public:

    NoServiceChargeChk();
    void addInterest(int time) override;
    bool checkBalance();

    virtual void deposit()override;
    virtual void withdraw()override;
    virtual void print()const override;
    virtual void writeCheck()override;

    double getMinBalance() const;
    double getInterestRate() override{
        return m_interest;
    }
    
    void setInterestRate(double intRate) override{
        m_interest = intRate;
    }
    void setMinBalance(double);

    void setBalance(double amt) override{
        m_balance = amt;
    }
    double getBalance() override{
        return m_balance;
    }

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

    double getInterestRate() override{
        return m_interest;
    }

    double getMinBalance() const{
        return m_minBalance;
    }

    void setInterestRate(double rate) override{
        m_interest = rate;
    }

    void setMinBalance(double amt){
        m_minBalance = amt;
    }

    void setBalance(double amt) override{
        m_balance = amt;
    }
    double getBalance() override{
        return m_balance;
    }

    void addInterest(int time) override{
      std::ofstream out("statements.txt", std::ios::app);
          double irAmt = 0.0;

          irAmt = m_balance * m_interest * time;
          out << "ADDED INTEREST: " << irAmt << '\n';
          out.close();

          m_balance += irAmt;
}

    protected:
    double m_interest;
    double m_minBalance;
};

//----------

template<typename T>
  class CheckingAdapter: public CheckingAcc {
    public:
      CheckingAdapter(T obj) : obj_(std::move(obj)) {}
      virtual void writeCheck() override{
        obj_.writeCheck();
      }

      virtual void deposit() override{};
      virtual void print() const override{};
      virtual void withdraw() override{};

      virtual void setBalance(double amt) override {
        obj_.setBalance(amt);
      }
      virtual double getBalance() override {
        return obj_.getBalance();
      }

      virtual void setInterestRate(double amt) override{
        obj_.setInterestRate(amt);
      }

      virtual double getInterestRate() override{
        return obj_.getInterestRate();
      }
      virtual void addInterest(int time) override{
        obj_.addInterest(time);
      }

    private:
      T obj_;
};

class CheckingCompat {
 public:
  template<typename T>
  CheckingCompat(T obj):m_account(std::make_shared<CheckingAdapter<T>>(std::move(obj))) {}
    virtual void setBalance(double amt) {
      m_account->setBalance(amt);
    }
    virtual double getBalance() {
      return m_account->getBalance();
    }
    virtual void getInterestRate() {
      m_account->getInterestRate();
    }
    virtual void addInterest(int time) {
      m_account->addInterest(time);
    }
  ~CheckingCompat() {}
 private:
  std::shared_ptr<CheckingAcc>m_account;
  };

#endif
