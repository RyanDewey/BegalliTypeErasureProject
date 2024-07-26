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
}
