.PHONY: all
all: main dynamic_lib.so


.PHONY: run
run: all
	./main


.PHONY: clean
clean:
	-rm main
	-rm dynamic_lib.so

main: main.cpp
	g++ main.cpp -o main


dynamic_lib.so: dynamic_lib.cpp
	g++ -fPIC -shared dynamic_lib.cpp -o dynamic_lib.so
