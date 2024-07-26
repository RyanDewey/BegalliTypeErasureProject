#include "highInterestSavings.h"
#include "serviceChargeChecking.h"
#include "noServiceChargeChk.h"
#include "cd.h"
enum ACCOUNTS{SAVINGS = 1, HIGH_INT_SAVE, SERVICE_CHARGE_CHK, NO_SERVICE_CHK,
HIGH_INT_CHK, CertD};
enum DETAIL{DEPOSIT = 1, WITHDRAW, PRINT, STATEMENT, WRITECHECK};

int mainScreen();
int accScreen();
int detailsScreenSaving();
int detailsScreenChecking();
const int months = 1;

int main() {
    int createAcc = 0;
    int accChoice = 0;
    int detail = 0;

    SavingsAcc s1;
    HighInterestSavings s2;
    //ServiceChargeChecking s3;
    NoServiceChargeChk s4;
    HighInterestChk s5;
    CD s6;

    //int test() {
    //CheckingAdapter test1 = new CheckingAdapter(NoServiceChargeChk());
    //CheckingAdapter test2 = new CheckingAdapter(HighInterestChk());

    CheckingAdapter test1(s4);
    CheckingAdapter test2(s5);

    test1.setBalance(500);
    test2.setBalance(1000);

    std::cout << "Balance for test1: " << test1.getBalance() << std::endl;
    std::cout << "Balance for test2: " << test2.getBalance() << std::endl; 
    std::cout << "Setting Balance for test1 to 2000: (and calling getter):";
    test1.setBalance(2000);
    std::cout << test1.getBalance() << std::endl;
    std::cout << "Setting Balance for test2 to 2500: (and calling getter):";
    test2.setBalance(2500);
    std::cout << test2.getBalance() << std::endl;
    std::cout << "Interest Rate for test1: " << test1.getInterestRate() << std::endl;
    std::cout << "Interest Rate for test2: " << test2.getInterestRate() << std::endl;
    std::cout << "Adding 1 month of interest to test1, new balance: $";
    test1.addInterest(1);
    std::cout << test1.getBalance() << std::endl;
    std::cout << "Adding 1 month of interest to test2, new balance: $";
    test2.addInterest(1);
    std::cout << test2.getBalance() << std::endl;
    std::cout << "Adding 1 more month of interest to both accounts." << std::endl;
    test1.addInterest(1);
    test2.addInterest(1);
    std::cout << "Test 1 balance: $" << test1.getBalance() << std::endl;
    std::cout << "Test 2 balance: $" << test2.getBalance() << std::endl;

    CheckingCompat t[] = {CheckingCompat(NoServiceChargeChk()), CheckingCompat(HighInterestChk())};
    for(auto x: t){
      x.setBalance(800);
      x.addInterest(1);
      std::cout << "Balance: $" << x.getBalance() << std::endl;
    }


    /*createAcc = mainScreen();
    while(createAcc != 2) {

        accChoice = accScreen();
        std::cout << '\n';
        switch(accChoice) {
            case SAVINGS: s1.getInfo();
                          s1.addInterest(months);
                          do{
                            detail = detailsScreenSaving();
                            switch(detail) {
                            case DEPOSIT: s1.deposit();
                            break;
                            case WITHDRAW: s1.withdraw();
                            break;
                            case PRINT: s1.print();
                            break;
                            case STATEMENT: s1.monthlyStatement();
                            break;
                            default: std::cout << "\nExiting Menu\n";
                            }
                          }while(detail < 5);
                          
            break;
            case HIGH_INT_SAVE: s2.getInfo();
                            if(!(s2.checkBalance())) {
                                std::cout << "unable to create account -- insufficient funds\n\n";
                        } else {
                            s2.addInterest(months);
                            do{
                                detail = detailsScreenSaving();
                                switch(detail) {
                                case DEPOSIT: s2.deposit();
                                break;
                                case WITHDRAW: s2.withdraw();
                                break;
                                case PRINT: s2.print();
                                break;
                                case STATEMENT: s2.monthlyStatement();
                                break;
                                default: std::cout << "\nExiting Menu\n";
                                }
                          }while(detail < 5);
                     }
            break;
            case SERVICE_CHARGE_CHK: s3.getInfo();
                            do{
                                detail = detailsScreenChecking();
                                switch(detail) {
                                case DEPOSIT: s3.deposit();
                                break;
                                case WITHDRAW: s3.withdraw();
                                break;
                                case PRINT: s3.print();
                                break;
                                case STATEMENT: s3.monthlyStatement();
                                break;
                                case WRITECHECK: s3.writeCheck();
                                break;
                                default: std::cout << "Exiting Menu\n";
                            }
                          }while(detail < 6);
            break;
            case NO_SERVICE_CHK: s4.getInfo();
                                if(!(s4.checkBalance())) {
                                    std::cout << "Unable to create account -- insufficient funds\n\n";
                                } else {
                                    s4.addInterest(months);
                                    do{
                                        detail = detailsScreenChecking();
                                        switch(detail) {
                                        case DEPOSIT: s4.deposit();
                                        break;
                                        case WITHDRAW: s4.withdraw();
                                        break;
                                        case PRINT: s4.print();
                                        break;
                                        case STATEMENT: s4.monthlyStatement();
                                        break;
                                        case WRITECHECK: s4.writeCheck();
                                        break;
                                        default: std::cout << "\nExiting Menu\n";
                                    }
                          }while(detail < 6);
                     }
                break;
                case HIGH_INT_CHK: s5.getInfo();
                                if(!(s5.checkBalance())) {
                                    std::cout << "Unable to create account -- insufficient funds\n\n";
                                } else {
                                    //s5.addInterest(months);
                                    do{
                                        detail = detailsScreenChecking();
                                        switch(detail) {
                                        case DEPOSIT: s5.deposit();
                                        break;
                                        case WITHDRAW: s5.withdraw();
                                        break;
                                        case PRINT: s5.print();
                                        break;
                                        case STATEMENT: s5.monthlyStatement();
                                        break;
                                        case WRITECHECK: s5.writeCheck();
                                        break;
                                        default: std::cout << "\nExiting Menu\n";
                                        }
                                     }while(detail < 6);
                                }
                    break;
                    case CertD: s6.getInfo();
                          s6.setMaturity();
                          s6.setMonth(months);
                          s6.addInterest(months);
                          do{
                            detail = detailsScreenSaving();
                            switch(detail) {
                            case DEPOSIT: s6.deposit();
                            break;
                            case WITHDRAW: s6.withdraw();
                            break;
                            case PRINT: s6.print();
                            break;
                            case STATEMENT: s6.monthlyStatement();
                            break;
                            default: std::cout << "\nExiting Menu\n";
                            }
                          }while(detail < 5);
                          
                    break;
        }
    std::ofstream clean("statements.txt");
    clean.close();
    createAcc = mainScreen();

    }
    return 0;
}


int mainScreen() {

    int choice = 0;
    do
    {
        std::cout << "WELCOME TO MAZE BANK\n------------------\n";
        std::cout << "1 - Create a new account\n"
                << "2 - Exit\n"
                << "Select option:   ";
        std::cin >> choice;
        std::cin.ignore();
    } while (choice > 2 || choice < 1 );
    return choice;
    
}

int accScreen() {
    int accChoice = 0;

    do{
        std::cout << "Please select an account to open:\n\n";
        std::cout << "SAVINGS\n-----------\n"
        <<"1 - Savings\n"
        <<"2 - High Interest Savings (minimum balance of $400)\n\n"
        << "CHECKING\n-------------\n"
        << "3 - Service Charge Checking\n"
        << "4 - No Service Charge Checking (minimum balance of $400)\n"
        << "5 - High Interest Checking (minimum balance of $1000)\n\n"
        << "OTHER\n-----------\n"
        << " 6 - Certificate of Deposit\n"
        << "Select option:   ";
        std::cin >> accChoice;
        std::cin.ignore();
    } while (accChoice > 6 || accChoice < 1);

    return accChoice;
}

int detailsScreenSaving() {
    int detail = 0;

    std::cout << "MENU:\n"
    << "1 - Deposit\n"
    << "2 - Withdraw\n"
    << "3 - Display Account Details\n"
    << "4 - Display Monthly Statements\n"
    << "5 - Exit\n"
    << "Select option:   ";;
    std::cin  >> detail;
    std::cin.ignore();
    std::cout << '\n';

    return detail;
}

int detailsScreenChecking() {
    int detail = 0;

    std::cout << "MENU:\n"
    << "1 - Deposit\n"
    << "2 - Withdraw\n"
    << "3 - Display Account Details\n"
    << "4 - Display Monthly Statements\n"
    << "5 - Write a check\n"
    << "6 - Exit\n"
    << "Select option:   ";
    std::cin  >> detail;
    std::cin.ignore();
    std::cout << '\n';

    return detail;*/  
}
