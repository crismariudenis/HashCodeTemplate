single: src/main.cpp  src/input.cpp  src/output.cpp  src/evaluator.cpp
	g++ src/main.cpp src/input.cpp src/output.cpp src/evaluator.cpp -o main -O3 

multi: src/main2.cpp src/input.cpp src/output.cpp src/evaluator.cpp
	g++ src/main2.cpp src/input.cpp src/output.cpp src/evaluator.cpp -o main2 -O3

run:
	./main.exe

run2:
	./main2.exe

clean:
	del main.exe main2.exe