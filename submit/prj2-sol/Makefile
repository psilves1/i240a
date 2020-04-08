CXX = g++
CXXFLAGS = -g -Wall -std=c++17

OFILES = seq-test.o command.o
OFILESNUM = nums.o
TARGET = seq-test nums

 

all:	$(TARGET)

 

seq-test:	$(OFILES)
			$(CXX) $(OFILES) -o $@

 

nums:	$(OFILESNUM)
		$(CXX) $(OFILESNUM) -o $@

 

.phony:	clean

clean:
		rm -f *~ *.o $(TARGET)