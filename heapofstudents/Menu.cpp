#include <vector>
#include <fstream>
#include <iostream>
#include "Student.h"
#include "Address.cpp"
#include "Date.cpp"


void loadStudents(std::vector<Student*>& students);







std::string menu();
//void loadStudent(vector<Students*>& students);

int main(){
	std::string response = "";
	std::vector<Student*> students;
	bool keepGoing = true;
	while (keepGoing){
	response = menu();
	
	/*
	if (response == "0"){
		keepGoing = false;
	} else if (response == "1"){
		showStudentNames(students);
	} else if (response == "2") {
		printSudents(students);
	} else if (response == "3") {
		findStudent(students);
	} else {
		std::cout << "Invaild Choice.";
		}
	}
		*/
	loadStudents(students);
	return 0;
}
}


std::string menu(){
		std::string response;

	    std::cout << "0) Load Students";
		std::cout << "1) Show Student Names";
		std::cout << "2) Print Student Data";
		std::cout << "3) Find a Student";
		std::cin >> response;
		getline(std::cin, response);
		return response;
}


			
void loadStudents(std::vector<Student*>& students) {
	std::ifstream inFile;
	inFile.open("student.csv");
	std::string currentLine; 


	while(getline(inFile, currentLine)){
		Student* student = new Student();
		student -> init(currentLine);

		students.push_back(student);
	}
inFile.close();

for (auto& item: students){
	item->printStudent();
} 
}





	
	
	
	
	
	









