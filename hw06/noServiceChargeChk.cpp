#include "noServiceChargeChk.h"

NoServiceChargeChk::NoServiceChargeChk():m_interest(0.07), m_minBalance(400){}
void NoServiceChargeChk::addInterest(int time){
    std::ofstream out("statements.txt", std::ios::app);
        double irAmt = 0.0;

        irAmt = m_balance * m_interest * time;
        out << "ADDED INTEREST: " << irAmt << '\n';
        out.close();

        m_balance += irAmt;
}

bool NoServiceChargeChk::checkBalance(){
    if (m_balance < m_minBalance) {
        return false;
    }
    return true;
}

void NoServiceChargeChk::deposit(){
        std::ofstream out("statements.txt", std::ios::out | std::ios::app);
        double depo = 0.0;
        std::cout << "Enter the deposit amount: $";
        std::cin >> depo;
        std::cin.ignore();

        m_balance += depo;
        out << "DEPOSIT: $" << depo << '\n';
        out.close();

    }

void NoServiceChargeChk::withdraw(){
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
void NoServiceChargeChk::print()const{
     std::cout << "NO SERVICE CHARGE CHECKING ACCOUNT DETAILS\n-----------------------\n"
        << "ACCOUNT ID: " << m_acnum << '\n'
        << "NAME: " << m_name << '\n'
        << "BALANCE: $" << m_balance << '\n'
        << "INTEREST RATE: " << (m_interest*100) << "%\n";
        std::cout << "\n\n";
}
void NoServiceChargeChk::writeCheck(){
    std::ofstream out("statements.txt", std::ios::app);
    out << "CHECK ";
    out.close();

    withdraw();
}

NoServiceChargeChk::~NoServiceChargeChk(){}