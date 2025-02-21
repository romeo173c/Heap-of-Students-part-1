studentTest: Address.o Date.o Student.o main.o
	g++ -g Address.o Date.o Student.o main.o -o studentTest

Address.o: Address.h Address.cpp
	g++ -c -g Address.cpp

Date.o: Date.h Date.cpp 
	g++ -c -g Date.cpp

Student.o: Student.h Student.cpp
	g++ -c -g Student.cpp 


main.o: main.cpp Date.h Date.cpp Address.h Address.cpp
	g++ -c -g main.cpp 

run:
	./studentTest


debug: studentTest
	gdb studentTest
