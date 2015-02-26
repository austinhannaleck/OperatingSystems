PROGRAM = findPrimesShared

all: run
run: zip
zip: build
build: clean

run:
	./$(PROGRAM).o

zip:
	rm -f $(PROGRAM).zip
	zip $(PROGRAM).zip *.cpp *.h makefile

build:
	g++ -std=c++11 findPrimes.cpp -o findPrimes.out
	g++ -std=c++11 findPrimesShared.cpp -o $(PROGRAM).out
    
clean:
	rm -f *.zip
	rm -f *.o
