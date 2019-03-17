.PHONY: main clean

main:
	g++ -O3 -Wall --std=c++11 -march=native -o main main.cpp simd_helper.cpp
clean:
	rm -rf main
