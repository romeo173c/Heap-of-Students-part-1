#ifndef STUDENTS_H_EXISTS
#define STUDENTS_H_EXISTS

#include <string>
#include "Date.h"
#include "Address.h"


class Student {
    protected:
        std::string student;
        std::string firstName;
        std::string lastName;
        Address* address;
        Date* dob;
        Date* expectedGrad;
        int creditHours;

    public:
         Student();
         Student(std::string studentString);
         ~Student();
         void init(std::string studentString);
         void printStudent();
         std::string getLastFirst();
         std::string getLastName();
         
         
};

#endif