#include "Student.h"
#include "Address.h"
#include "Date.h"
#include <iostream>
#include <sstream>


Student::Student(){
    firstName = " ";
    lastName = " ";
    address = new Address();
    expectedGrad = new Date();
    dob = new Date();
    creditHours = 0;

}

Student::~Student(){
    delete dob;
    delete expectedGrad;
    delete address; 

}


void Student::init(std::string studentString){
    std::stringstream ss (studentString);
    std:: string street;
    std:: string city;
    std:: string state;
    std:: string zip;
    std:: string tDob;
    std:: string grad;

    getline(ss,firstName, ',');
    getline(ss,lastName, ',');
    getline(ss,street, ',');
    getline(ss,city, ',');
    getline(ss,state, ',');
    getline(ss,zip,',');
    getline(ss,tDob, ',');
    getline(ss,grad, ',');
    ss >> creditHours;

    ss.clear();
    ss.str();


    address->init(street, city, state, zip);
    dob->init(tDob);
    Student::expectedGrad-> init(grad);    


}

void Student::printStudent(){
    std:: cout << firstName << " " << lastName << std:: endl;
    Student::address->printAddress();
    std::cout << "DOB: ";
    Student::dob->printDate();
    std::cout << "Grad: ";
    expectedGrad->printDate();
    std::cout << "Credit Hours: " << creditHours << std::endl;
    std::cout << "________________________________________________________________________________" <<std::endl;
}



std::string Student::getLastFirst(){
    std ::stringstream ss;
    ss << lastName <<  ',' << firstName;
    return ss.str();
}

std::string Student::getLastName(){
    return Student::lastName;
}

