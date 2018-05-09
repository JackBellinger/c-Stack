all: Stack clean

Stack: instantiation.cpp Lab4.o Stack.o Student.o
	g++ -o Stack instantiation.cpp

Lab4.o: Lab4.cpp
	g++ -c Lab4.cpp Stack.cpp Student.cpp

clean:
	rm -rf *o
