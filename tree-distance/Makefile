.PHONY: clean, mrproper
CC = g++
CXXFLAGS = -g -Wall -std=c++14

all: tree-distance.bin

%.o: %.cpp
	$(CC) $(CXXFLAGS) -c -o $@ $<

tree-distance.bin: main.o
	$(CC) $(CXXFLAGS) -o $@ $+

clean:
	rm -f *.o

mrproper: clean
	rm -f tree-distance.bin
