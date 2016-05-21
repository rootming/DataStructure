CXX = g++
CXXFLAGS = -g
TARGET = array link


#all:$(TARGET)
#	$(CXX) -g -o array array.o
#	$(CXX) -g -o link link.o

$(TARGET):array.o link.o
	$(CXX) -g -c -o array.o array.cpp
	$(CXX) -g -c -o link.o link.cpp
	
.PHONY:clean

clean:
	rm *.o $(TARGET)
