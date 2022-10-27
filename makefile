all: main
main: main.cpp
	g++ -o $@ main.cpp
clean: 
	rm -f main *.o