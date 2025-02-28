#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include "Date.h"
#include "Address.h"
#include "Student.h"

void testAddress();
void testDate();
void testStudent();
void loadStudents(std::vector<Student*>& students);
void printStudents(std::vector<Student*>& students);
void showStudentNames(std::vector<Student*>& students);
void findStudent(std::vector<Student*>& students);

int main(){
  std::vector<Student*> students;
  std::cout << "Hello!" << std::endl;



  std::string response = "";

  
  
	bool keepGoing = true;
  loadStudents(students);
	while (keepGoing){

    std::cout << "0) Exit \n"; 
    std::cout << "1) Show Student Names \n";
    std::cout << "2) Print Student Names \n";
    std::cout << "3) Find Student \n" << std::endl;

	getline(std::cin, response);
	
	
	if (response == "0"){
		keepGoing = false;
	} else if (response == "1"){
		showStudentNames(students);
	} else if (response == "2") {
		printStudents(students);
	} else if (response == "3") {
		findStudent(students);
	} else {
		std::cout << "Invaild Choice.";
		}
	}
		
	
	






/*
  testAddress();
  testDate();
  testStudent();
  loadStudents(students);
  printStudents(students);
  showStudentNames(students);
  findStudent(students);*/

  return 0;
} 

void testAddress(){
  Address a;
  a.init("123 W Main St", "Muncie", "IN", "47303");
  a.printAddress();
} // end testAddress

void testDate(){
 Date d;
 d.init("01/27/1997");
 d.printDate();
} // end testDate

void testStudent(){
  std::string studentString = "Danielle,Johnson,32181 Johnson Course Apt. 389,New Jamesside,IN,59379,02/17/2004,05/15/2027,65";
  Student* student = new Student();
  student->init(studentString);
  student->printStudent();
  std::cout << std::endl;
  std::cout << student->getLastFirst();
  delete student;
} // end testStudent 


void loadStudents(std::vector<Student*>& students) {
	std::ifstream inFile;
	inFile.open("students.csv");
	std::string currentLine; 


	while(getline(inFile, currentLine)){
		Student* student = new Student();
		student -> init(currentLine);

		students.push_back(student);
	}
inFile.close();

} 


void printStudents(std::vector<Student*>& students){
  for (auto& item: students){
	item->printStudent();
  }
}

void deleteStudents(std::vector<Student*>& students){
  for (auto& person: students){
	        delete person;
  }
}


void showStudentNames(std::vector<Student*>& students){
          std::cout << "Student Names";
          for (const auto& student: students){
            std::cout << student->getLastFirst() << std::endl;
          }
}


void findStudent(std::vector<Student*>& students){
  std:: string findLastName;
  std:: string findName;
  std:: stringstream ss;
  
  std::cout << "Please Enter Last Name\n";
  getline(std::cin, findName);

  for (auto& item: students){
    ss.clear();
    ss.str(item->getLastFirst());
    getline(ss, findLastName, ',');
    
    size_t found = findLastName.find(findName);

    if (found!= std::string::npos){
      item->printStudent();

    } 
  }

}