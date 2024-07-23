CC = g++
OBJECTS = savingsAcc.o  bankAccount.o hw06.o highInterestSavings.o checkingAcc.o serviceChargeChecking.o noServiceChargeChk.o highInterestChk.o cd.o
all = output

output: $(OBJECTS)
	$(CC) $(OBJECTS) -o output

hw06.o: hw06.cpp
	$(CC) -c hw06.cpp

bankAccount.o: bankAccount.cpp
	$(CC) -c bankAccount.cpp

savingsAcc.o: savingsAcc.cpp 
	$(CC) -c savingsAcc.cpp

highInterestSavings.o: highInterestSavings.cpp
	$(CC) -c highInterestSavings.cpp

checkingAcc.o: checkingAcc.cpp
	$(CC) -c checkingAcc.cpp

serviceChargeChecking.o: serviceChargeChecking.cpp
	$(CC) -c serviceChargeChecking.cpp

noServiceChargeChk.o: noServiceChargeChk.cpp
	$(CC) -c noServiceChargeChk.cpp

highInterestChk.o: highInterestChk.cpp
	$(CC) -c highInterestChk.cpp

cd.o: cd.cpp
	g++ -c cd.cpp

clean:
	rm*.o output