#include "serviceChargeChecking.h"

ServiceChargeChecking::ServiceChargeChecking():m_maxChecks(3), m_numChecks(0), m_serviceCharge(15.0){}

void ServiceChargeChecking::monthlyServiceFee(int time){
    m_balance -= (time * m_serviceCharge);
}
void ServiceChargeChecking::deposit(){
    std::ofstream out("statements.txt", std::ios::out | std::ios::app);
    double depo = 0.0;
    std::cout << "Enter the deposit amount: $";
    std::cin >> depo;
    std::cin.ignore();

    m_balance += depo;
    out << "DEPOSIT: $" << depo << '\n';
    out.close();
}
void ServiceChargeChecking::withdraw(){
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
void ServiceChargeChecking::print()const{
    std::cout << "SERVICE CHARGE CHECKING ACCOUNT DETAILS\n-----------------------\n"
    << "ACCOUNT ID: " << m_acnum << '\n'
    << "NAME: " << m_name << '\n'
    << "BALANCE: $" << m_balance << '\n'
    << "MONTHLY CHARGE: " << m_serviceCharge << '\n';
    std::cout << "\n\n";
}
void ServiceChargeChecking::writeCheck(){
    if(m_numChecks == m_maxChecks) {
        std::cout << "DECLINED -- Reached maximum check limit this month\n";
    } else {
        m_numChecks++;
        std::ofstream out("statements.txt", std::ios::app);
        out << "CHECK ";
        out.close();

        withdraw();
        std::cout << "You have " << (m_maxChecks - m_numChecks) << " checks remaining this month!\n\n";
    }

}

ServiceChargeChecking::~ServiceChargeChecking(){}
