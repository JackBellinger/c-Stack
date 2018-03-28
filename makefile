all: Stack clean

Stack: instantiation.cpp Lab4.o Stack.o Student.o
	g++ -std=c++11 -o Stack instantiation.cpp

Lab4.o: Lab4.cpp
	g++ -std=c++11 -c Lab4.cpp Stack.cpp Student.cpp

clean:
	rm -rf *o
