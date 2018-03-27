CC=g++
CXXFLAG=-Wall
EXEC_TEST=test-calculator
EXEC_PROG=calculator
EXEC_ALL=test-calculator calculator

ifneq ("$(wildcard .depend)","")
FILE_EXISTS = 1
endif

ifeq ($(FILE_EXISTS),)
all::
	@echo "Execute in first : make depend"
else
all:: $(EXEC_PROG)
endif

depend::
	@$(CC) -MM *.cpp $(CXXFLAG) >| .depend

-include .depend


test:: $(EXEC_TEST)

calculator: calculator.o main.o pile.o
	$(CC) -o $@ $^

test-calculator: CSVParser.o Person.o Fraction.o TestCSVParser.o
	$(CC) -o $@ $^


%.o: %.cpp
	$(CC) -c $^ $(CXXFLAG) 


cleaner: clean
	@rm -f $(EXEC_ALL)

clean: 
	@rm -f *.o
	@rm -f *.gch
	@rm .depend 2>/dev/null

