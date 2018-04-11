CC=g++
CXXFLAG=-std=c++11 -Wall 
LIBS=`wx-config --cxxflags --libs`
INCLUDES = -include wx/wx.h
DEPS = $(wildcard *.hpp)
EXEC_TEST=
EXEC_ALL=$(EXEC_TEST) myapp

#ifneq ("$(wildcard .depend)","")
#FILE_EXISTS = 1
#endif

#ifeq ($(FILE_EXISTS),)
#all::
#	@echo "Execute in first : make depend"
#else
all:: $(EXEC_ALL)
#endif

#depend::
#	@$(CC) -MD -MP *.cpp $(CXXFLAG) $(LIBS) >| .depend

#-include .depend


test:: $(EXEC_TEST)

myapp: myapp.o MainFrame.o
	$(CC) -o $@ $^ $(LIBS)


%.o: %.cpp %.hpp
	$(CC) -c $< $(CXXFLAG) $(LIBS) $(INCLUDES)


cleaner: clean
	rm -f $(EXEC_ALL)

clean: 
	rm -f *.o
	rm -f *.gch

