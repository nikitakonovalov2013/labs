CXX=g++
TARGET=bignum
SOURCES=main.cpp bignum.cpp

all: 
	$(CXX) $(SOURCES) -o $(TARGET) -g

clear:
	rm -rf *.o $(TARGET)
