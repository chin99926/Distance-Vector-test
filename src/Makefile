.PHONY : all clean

CXX = g++

CFLAGS = -O3 -std=c++0x
CSRCS = $(wildcard *.cpp)
COBJS = $(addsuffix .o, $(basename $(CSRCS)))

main : $(COBJS)
	@echo "> Building $@"
	@$(CXX) $(CFLAGS) $^ -o $@

main.o : main.cpp dvrMgr.h dvrNode.h
	@echo "> Compiling $@"
	@$(CXX) $(CFLAGS) -c $< -o $@

%.o : %.cpp %.h 
	@echo "> Compiling $@"
	@$(CXX) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(COBJS)
