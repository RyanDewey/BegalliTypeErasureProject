
#include "bankAccount.h"

BankAccount::BankAccount():m_name(""), m_balance(0.0), m_acnum(0){}
    
void BankAccount::getInfo(){
    std::cout << "Please enter the account details below:\n---------------\n";
    std::cout << "ACCOUNT ID: ";
    std::cin >> m_acnum;
    std::cin.ignore();

    std::cout <<  "NAME:   ";
    getline(std::cin, m_name);

    std::cout << "BALANCE:  $";
    std::cin >> m_balance;
    std::cin.ignore();
    std::cout << "\n\n";
}


void BankAccount::monthlyStatement()const{
    std::string statements;
    std::fstream in("statements.txt", std::ios::in);

    std::cout << "MONTHLY STATEMENTS\n-----------------\n";
    while(getline(in, statements)) {
        std::cout << statements << '\n';
    }
    std::cout << '\n';

} 

double BankAccount::getBalance()const{
    return m_balance;
}

void BankAccount::setBalance(double amt){
    m_balance = amt; 
}


BankAccount::~BankAccount(){}