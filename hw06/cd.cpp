#include "cd.h"

CD::CD():m_maturityMonths(0), m_currMonth(0), m_interest(.15), m_withdrawPenalty(10.0), m_compound(0.0){}

void CD::addInterest(int time){
    std::ofstream out("statements.txt", std::ios::app);
    double irAmt = 0.0;
    irAmt = m_balance * m_interest * time;

    if(time < m_maturityMonths) {
        out << "COMPUNDED INTEREST: " << irAmt << '\n';
        out.close();
        m_compound += irAmt;
    } else {
        out << "ADDED INTEREST: " << irAmt << '\n';
        out.close();
        m_balance += m_compound;
    }
        
}

void CD::setMonth(const int month) {
    m_currMonth = month;
}

void CD::setMaturity(){
    int maturityMonths = 0;
    std::cout << "please enter the time (in months) that this Certificate of Deposit will mature for:\n"
    << "Number of Months: ";
    std::cin >> maturityMonths;
    std::cin.ignore();

    m_maturityMonths = maturityMonths;
}
void CD::deposit(){
    if(m_currMonth < m_maturityMonths) {
        std::cout << "WARNING -- Cannot deposit money until CD is full matured\n\n";
    } else {
        std::ofstream out("statements.txt", std::ios::out | std::ios::app);
        double depo = 0.0;
        std::cout << "Enter the deposit amount: $";
        std::cin >> depo;
        std::cin.ignore();

        m_balance += depo;
        out << "DEPOSIT: $" << depo << '\n';
        out.close();
    }
    
}
void CD::withdraw(){
    char ans = ' ';
    std::cout << "WARNING -- there will be a penalty for withdrawing before maturity date\n"
            << "You still have: " << m_maturityMonths - m_currMonth << " months remaining!\n\n";
    std::cout << "Do you wish to continue? (y/n): ";
    std::cin.get(ans);

    if(toupper(ans) == 'N') {

    } else {
        std::ofstream out("statements.txt", std::ios::out | std::ios::app);
        double withdraw = 0.0;

        std::cout << "You have $" << m_balance << '\n';
        std::cout << "Enter the amount to withdraw:   ";
        std::cin >> withdraw;

        while(withdraw > (m_balance - m_withdrawPenalty)) {
            std::cout << "Withdraw DECLINED -- Insufficient funds\n\n";
            std::cout << "You have $" << m_balance << '\n';
            std::cout << "Enter the amount to withdrawl:   ";
            std::cin >> withdraw;
        }

        m_balance = m_balance - withdraw - m_withdrawPenalty;
        std::cin.ignore();

        out << "WITHDRAW: $" << withdraw << '\n';
        out << "WITHDRAW FEE: $" << m_withdrawPenalty << '\n';
        out.close();
    }
    
}
void CD::print()const{
    std::cout << "CERTIFICATE OF DEPOSIT ACCOUNT DETAILS\n-----------------------\n"
        << "ACCOUNT ID: " << m_acnum << '\n'
        << "NAME: " << m_name << '\n'
        << "BALANCE: $" << m_balance << '\n'
        << "MATURITY MONTHS: " << m_maturityMonths << '\n'
        << "CURRENT MONTH: " << m_currMonth << '\n'
        << "INTEREST RATE: " << (m_interest*100) << "%\n";
        std::cout << "\n\n";

}
CD::~CD(){}
