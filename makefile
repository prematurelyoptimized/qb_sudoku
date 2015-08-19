MAINSRC := $(wildcard src/lib/*.cpp) 
TESTSRC := $(wildcard test/*.cpp)
LDFLAGS :=
LDADD := -lcpptest -Lsrc -Lsrc/lib
CXXFLAGS := -Wall -Wextra -pedantic -g -MMD -std=c++0x -Iinclude -O3 -I../lib
CC := g++

OBJFILES := $(MAINSRC:.cpp=.o)
TESTOBJ := $(TESTSRC:.cpp=.o)
DEPFILES := $(MAINSRC:.cpp=.d) $(TESTSRC:.cpp=.d)

all : hardcode clitool speedtest

hardcode: src/solve.o $(OBJFILES)
	$(LINK.o) -o bin/solve $^ $(LDADD)

clitool: src/solveSDM.o $(OBJFILES)
	$(LINK.o) -o bin/solveSDM $^ $(LDADD)
	
test : $(TESTOBJ) $(OBJFILES)
	$(LINK.o) -o test/run_tests $^ $(LDADD)
	
speedtest: src/speedtest.o $(OBJFILES)
	$(LINK.o) -o bin/speedtest $^ $(LDADD)
	
clean :
	-rm -f bin/solve bin/solveSDM bin/speedtest test/run_tests $(OBJFILES) $(TESTOBJ) $(DEPFILES)
	
-include $(DEPFILES)
