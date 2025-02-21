#include "Date.h"
#include <iostream>
#include <sstream>

Date::Date(){
	dateString ="0/0/0000";
	month = 0;
	day = 0;
	year = 0;
}



void Date::init(std::string dateString){

	std::stringstream ss;
	std::string tMonth;
	std::string tDay;
	std::string tYear;


	ss.clear();
	ss.str(dateString);


	getline(ss, tMonth, '/');
	getline(ss, tDay, '/');
	getline(ss, tYear);


	ss.clear();
	ss.str("");

	
	ss << tDay << " " << tMonth << " " << tYear;
	ss >> day >> month >> year;
}


void Date::printDate(){
	std::string months[] = {"Null", "January", "February", "March", "April", "May", "June", "July", "Auguest", "September", "October", "November", "December"};


	std::cout << months[month] << " ";
	std::cout << day << " , "<< year << std::endl;

}


