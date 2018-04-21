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


ifneq ("$(wildcard make.d)","")
all:: $(EXEC_PROG)
else
all:: depend $(EXEC_PROG)
endif


depend::
		$(CC) -MM $(LIBS) $(INCLUDE) $(CXXFLAG) $(PATH_SRC)*.cpp >>make.d

-include make.d

test:: $(EXEC_TEST)

calculator:: $(OBJ_CALCULATOR)
	$(CC) -o $@ $^ $(LIBS)

$(PATH_TEST_BIN)test-calculator: $(OBJ_TEST_CALCULATOR)
	$(CC) -o $@ $^ $(LIBS)

$(PATH_TEST_BIN)test-pile: $(OBJ_TEST_PILE)
	$(CC) -o $@ $^ $(LIBS)

$(PATH_OBJ)TestCalculator.o: $(PATH_SRC)TestCalculator.cpp
	$(CC) -c $^ $(CXXFLAG) 
	@mv *.o $(PATH_OBJ)

$(PATH_OBJ)TestPile.o: $(PATH_SRC)TestPile.cpp
	$(CC) -c $^ $(CXXFLAG) 
	@mv *.o $(PATH_OBJ)

$(PATH_OBJ)%.o: $(PATH_SRC)%.cpp $(PATH_HEADERS)%.hpp
	$(CC) -c  $< $(CXXFLAG) $(LIBS)  $(INCLUDE)
	@mv *.o $(PATH_OBJ)




cleaner: clean
	@rm -f $(EXEC_TEST)
	@rm -f $(EXEC_PROG)

clean: 
	@rm -f $(PATH_OBJ)*.o
	@rm -f $(PATH_HEADERS)*.gch
	@rm -f make.d

