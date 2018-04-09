##
CC=g++
CXXFLAG=-Wall -std=c++11
EXEC_TEST=test-calculator
EXEC_PROG=calculator
EXEC_ALL=test-calculator

ifneq ("$(wildcard .depend)","")
FILE_EXISTS = 1
endif

ifeq ($(FILE_EXISTS),)
all::
	@echo "Execute in first : make depend"
else
all:: $(EXEC_ALL)
endif

depend::
	@$(CC) -MM *.cpp $(CXXFLAG) >| .depend

-include .depend


test:: $(EXEC_TEST)



test-calculator: TestCalculator.o calculator.o
	$(CC) -o $@ $^


%.o: %.cpp
	$(CC) -c $^ $(CXXFLAG) 


cleaner: clean
	@rm -f $(EXEC_ALL)

clean: 
	@rm -f *.o
	@rm -f *.gch
	@rm .depend 2>/dev/null

