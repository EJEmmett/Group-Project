#include <string>
#include "Person.h"

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee : public Person{
	public:
        Employee();
		void setInfo(std::string, std::string, std::string, int, float);
		float getRate() const;
		std::string print() const;
	private:
		std::string empID;
		int lvl;
		float cPH;
};

Employee::Employee(){
	setInfo("", "", "", 0, 0.0);
}

void Employee::setInfo(std::string f, std::string l, std::string id, int i, float cost){
	setName(f, l);
	empID = id;
	lvl = i;
	cPH = cost;
}

float Employee::getRate() const{
    return cPH;
}

std::string Employee::print() const{
	return first + " " + last + " " + empID;
}

#endif
