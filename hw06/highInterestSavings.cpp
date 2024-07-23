#include "highInterestSavings.h"

HighInterestSavings::HighInterestSavings():m_minBalance(400){
    m_interest = .09;
}
bool HighInterestSavings::checkBalance(){
    if (m_balance < m_minBalance) {
        return false;
    }
    return true;
}

void HighInterestSavings::deposit(){
    std::ofstream out("statements.txt", std::ios::out | std::ios::app);
        double depo = 0.0;
        std::cout << "Enter the deposit amount: $";
        std::cin >> depo;
        std::cin.ignore();

        m_balance += depo;
        out << "DEPOSIT: $" << depo << '\n';
        out.close();
}
void HighInterestSavings::withdraw(){
    std::ofstream out("statements.txt", std::ios::out | std::ios::app);
    double withdraw = 0.0;
    double temp = 0.0;

    std::cout << "You have $" << m_balance << '\n';
    std::cout << "Enter the amount to withdraw:   ";
    std::cin >> withdraw;

    while(withdraw > m_balance) {
        std::cout << "Insufficient funds, please try again\n\n";
        std::cout << "You have $" << m_balance << '\n';
        std::cout << "Enter the amount to withdrawl:   ";
        std::cin >> withdraw;
    }

        temp = m_balance - withdraw;
        while(temp < m_minBalance) {
            std::cout << "Insufficient funds - must have at least " << m_minBalance << " deposited"
            <<", please try again\n\n";
            std::cout << "You have $" << m_balance << '\n';
            std::cout << "Enter the amount to withdrawl:   ";
            std::cin >> withdraw;
            temp = m_balance - withdraw;

        }

        m_balance -= withdraw;
        std::cin.ignore();

        out << "WITHDRAW: $" << withdraw << '\n';
        out.close();
}
void HighInterestSavings::print()const{
     std::cout << "HIGH INTEREST SAVINGS ACCOUNT DETAILS\n-----------------------\n"
        << "ACCOUNT ID: " << m_acnum << '\n'
        << "NAME: " << m_name << '\n'
        << "BALANCE: $" << m_balance << '\n'
        << "INTEREST RATE: " << (m_interest*100) << "%\n";
        std::cout << "\n\n";
}
HighInterestSavings::~HighInterestSavings(){}