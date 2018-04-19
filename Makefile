CC=g++
CXXFLAG=-Wall -std=c++11
LIBS=`wx-config --cxxflags --libs`
INCLUDE = -include wx/wx.h

PATH_TEST_BIN=test-bin/
PATH_OBJ=obj/
PATH_SRC=src/
PATH_HEADERS=headers/

EXEC_TEST=$(PATH_TEST_BIN)test-calculator $(PATH_TEST_BIN)test-pile
EXEC_PROG=calculator



OBJ_TEST_PILE=$(PATH_OBJ)TestPile.o $(PATH_OBJ)Pile.o
OBJ_TEST_CALCULATOR=$(PATH_OBJ)TestCalculator.o $(PATH_OBJ)calculator.o $(PATH_OBJ)fonction_math.o $(PATH_OBJ)Pile.o
OBJ_CALCULATOR=$(PATH_OBJ)calculator.o $(PATH_OBJ)fonction_math.o $(PATH_OBJ)Pile.o $(PATH_OBJ)MainFrame.o obj/CalculatorApp.o

all:: $(EXEC_PROG)

depend::
	@touch .depends
	@makedepend -Y -Iheaders -f.depends $(PATH_SRC)*.cpp 2>/dev/null


-include .depends

test:: $(EXEC_TEST)

calculator:: $(OBJ_CALCULATOR)
	$(CC) -o $@ $^ $(LIBS)

$(PATH_TEST_BIN)test-calculator: $(OBJ_TEST_CALCULATOR)
	$(CC) -o $@ $^

$(PATH_TEST_BIN)test-pile: $(OBJ_TEST_PILE)
	$(CC) -o $@ $^

$(PATH_OBJ)MainFrame.o: $(PATH_SRC)MainFrame.cpp
	$(CC) -c  $^ $(CXXFLAG) $(LIBS)  $(INCLUDE)
	@mv *.o $(PATH_OBJ)

$(PATH_OBJ)CalculatorApp.o: $(PATH_SRC)CalculatorApp.cpp
	$(CC) -c  $^ $(CXXFLAG) $(LIBS)  $(INCLUDE)
	@mv *.o $(PATH_OBJ)

$(PATH_OBJ)%.o: $(PATH_SRC)%.cpp
	$(CC) -c  $< $(CXXFLAG)
	@mv *.o $(PATH_OBJ)


cleaner: clean
	@rm -f $(EXEC_TEST)
	@rm -f $(EXEC_PROG)

clean: 
	@rm -f $(PATH_OBJ)*.o
	@rm -f *.gch
	@rm -f .depend
	@rm -f .depend.bak

