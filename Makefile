CC=g++
CXXFLAG=-Wall -std=c++11
LIBS=`wx-config --cxxflags --libs`
INCLUDE = -include wx/wx.h
EXEC_TEST=test-calculator test-pile
EXEC_PROG=calculator
EXEC_ALL=$(EXEC_TEST) $(EXEC_PROG)




all:: $(EXEC_ALL)




test:: $(EXEC_TEST)

calculator:: calculator.o fonction_math.o Pile.o MainFrame.o CalculatorApp.o
	$(CC) -o $@ $^ $(LIBS)

test-calculator: TestCalculator.o calculator.o fonction_math.o Pile.o
	$(CC) -o $@ $^

test-pile: TestPile.o Pile.o
	$(CC) -o $@ $^

MainFrame.o: MainFrame.cpp
	$(CC) -c $^ $(CXXFLAG) $(LIBS)  $(INCLUDE)

CalculatorApp.o: CalculatorApp.cpp
	$(CC) -c $^ $(CXXFLAG) $(LIBS)  $(INCLUDE)

%.o: %.cpp
	$(CC) -c $^ $(CXXFLAG)


cleaner: clean
	@rm -f $(EXEC_ALL)

clean: 
	@rm -f *.o
	@rm -f *.gch

