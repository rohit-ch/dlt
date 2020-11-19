.PHONY: all

all: stack.o mystack

stack.o:
	g++ -c -Wall --std=c++14 -I./include src/stack.cpp -o obj/stack.o

mystack: stack.o
	g++ -Wall --std=c++14 -I./include src/main.cpp obj/stack.o -o bin/mystack

clean:
	rm ./bin/mystack ./obj/*.o
