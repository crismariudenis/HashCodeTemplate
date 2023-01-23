single: main
	.\main

main: main.cpp input.cpp output.cpp evaluator.cpp
	g++ main.cpp input.cpp output.cpp evaluator.cpp -o main -O3 

multi: main2
	.\main2

main2: main2.cpp input.cpp output.cpp evaluator.cpp
	g++ main2.cpp input.cpp output.cpp evaluator.cpp -o main2 -O3

clean:
	del main.exe main2.exe