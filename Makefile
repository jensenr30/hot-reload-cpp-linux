.PHONY: all
all: main dynamic-lib.so


.PHONY: run
run: all
	./main


main: main.cpp
	g++ main.cpp -o main


dynamic-lib.so: dynamic-lib.cpp
	g++ -fPIC -shared dynamic-lib.cpp -o dynamic-lib.so
