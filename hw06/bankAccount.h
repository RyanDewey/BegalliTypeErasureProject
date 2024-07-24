#ifndef _BANKACC_
#define _BANKACC_

#include <iostream>
#include <string>
#include <fstream>

class BankAccount{
    public:
    BankAccount();

    double getBalance() const;

    void setBalance(double);

    void getInfo();
    void monthlyStatement()const;
    
    virtual void deposit() = 0;
    virtual void withdraw() = 0;
    virtual void print()const = 0;

    virtual ~BankAccount();

    protected:
    std::string m_name;
    double m_balance;
    int m_acnum;

};

#endif