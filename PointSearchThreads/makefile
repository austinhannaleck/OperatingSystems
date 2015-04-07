PROGRAM = pointFinderThreads

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
	g++ -std=c++11 Child.cpp -o Child.o
	g++ -std=c++11 Controller.cpp -o $(PROGRAM).o
    
clean:
	rm -f *.zip
	rm -f *.o
