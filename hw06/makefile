CC = g++
CFLAGS = -std=c++20
OBJECTS = savingsAcc.o  bankAccount.o hw06.o highInterestSavings.o checkingAcc.o serviceChargeChecking.o noServiceChargeChk.o highInterestChk.o cd.o
all = output

output: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o output

hw06.o: hw06.cpp
	$(CC) $(CFLAGS) -c hw06.cpp

bankAccount.o: bankAccount.cpp
	$(CC) $(CFLAGS) -c bankAccount.cpp

savingsAcc.o: savingsAcc.cpp 
	$(CC) $(CFLAGS) -c savingsAcc.cpp

highInterestSavings.o: highInterestSavings.cpp
	$(CC) $(CFLAGS) -c highInterestSavings.cpp

checkingAcc.o: checkingAcc.cpp
	$(CC) $(CFLAGS) -c checkingAcc.cpp

serviceChargeChecking.o: serviceChargeChecking.cpp
	$(CC) $(CFLAGS) -c serviceChargeChecking.cpp

noServiceChargeChk.o: noServiceChargeChk.cpp
	$(CC) $(CFLAGS) -c noServiceChargeChk.cpp

highInterestChk.o: highInterestChk.cpp
	$(CC) $(CFLAGS) -c highInterestChk.cpp

cd.o: cd.cpp
	$(CC) $(CFLAGS) -c cd.cpp

clean:
	rm *.o output
