# Type Erasure Project

GITHUB LINK: https://github.com/RyanDewey/BegalliTypeErasureProject/tree/master/hw06

We implemented type erasure through our NoServiceChargeChk, and HighInterestChk. We created CheckingCompat which acted as a wrapper
using the functions:
addInterest()
setBalance()
getBalance()
getInterestRate()

Type erasure code was implemented mainly in the following files:
- noServiceChargeChk.h (holds all the relevant adapter, compat, and class definitions)
- noServiceChargeChk.cpp
- Base classes : bankAccount.h, checkingAcc.h
- hw06.cpp (tests)

Our tests were performed through instantiating checkingAdapters with both noServiceChargeChk and highInterestChk as parameters.
We then called all the possible functions through our type erasure model, and created an array for checkingCompat to issue
final tests for balance and interest.
