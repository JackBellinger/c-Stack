all: Stack clean

Stack: Lab4.o Stack.o Student.o
	g++ Lab4.o Stack.o Student.o -o Stack

Lab4.o: Lab4.cpp
	g++ -c Lab4.cpp Stack.cpp Student.cpp

Stack.o: Stack.cpp
	g++ -c Stack.cpp

Students.o: Student.cpp
	g++ -c Student.cpp

clean:
	rm -rf *o
