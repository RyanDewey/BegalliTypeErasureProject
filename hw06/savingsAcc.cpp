#include "savingsAcc.h"

    SavingsAcc::SavingsAcc():m_interest(.07){}

    void SavingsAcc::deposit(){
        std::ofstream out("statements.txt", std::ios::out | std::ios::app);
        double depo = 0.0;
        std::cout << "Enter the deposit amount: $";
        std::cin >> depo;
        std::cin.ignore();

        m_balance += depo;
        out << "DEPOSIT: $" << depo << '\n';
        out.close();

    }
    void SavingsAcc::withdraw(){
        std::ofstream out("statements.txt", std::ios::out | std::ios::app);
        double withdraw = 0.0;

        std::cout << "You have $" << m_balance << '\n';
        std::cout << "Enter the amount to withdraw:   ";
        std::cin >> withdraw;

        while(withdraw > m_balance) {
            std::cout << "Withdraw DECLINED -- Insufficient funds\n\n";
            std::cout << "You have $" << m_balance << '\n';
            std::cout << "Enter the amount to withdrawl:   ";
            std::cin >> withdraw;
        }

        m_balance -= withdraw;
        std::cin.ignore();

        out << "WITHDRAW: $" << withdraw << '\n';
        out.close();
    }

    void SavingsAcc::addInterest(int time) {
        std::ofstream out("statements.txt", std::ios::app);
        for(int i = 0; i < time; i++){
            m_balance *= (m_interest + 1);
            std::cout << "BALANCE FOR MONTH[" << i+1 << "]: " << m_balance << '\n';
            out << "BALANCE FOR MONTH[" << i+1 << "]: " << m_balance << '\n';
        }
        out.close();
    }

    void SavingsAcc::print()const{
        std::cout << "SAVINGS ACCOUNT DETAILS\n-----------------------\n"
        << "ACCOUNT ID: " << m_acnum << '\n'
        << "NAME: " << m_name << '\n'
        << "BALANCE: $" << m_balance << '\n'
        << "INTEREST RATE: " << (m_interest*100) << "%\n";
        std::cout << "\n\n";
    }

    SavingsAcc::~SavingsAcc(){}