#define C++ compiler and flags
CXX = g++
CXXFLAGS = -g -Wall -std=c++17

#define object files to be produces
OFILES = \
  main.o

TARGET = main

all:		$(TARGET)

$(TARGET):	$(OFILES)
		$(CXX) $(OFILES) -o $@

.phony:		clean
clean:
		rm -f *~ *.o $(TARGET)
