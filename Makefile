include ${SYSTEMC_HOME}/examples/build-unix/Makefile.config 
 
PROJECT := sc_main 
SRCS    := $(wildcard *.cpp) 
OBJS    := $(SRCS:.cpp=.o) 
 
include ${SYSTEMC_HOME}/examples/build-unix/Makefile.rules