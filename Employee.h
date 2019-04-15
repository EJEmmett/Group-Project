#include <string>
#include "Person.h"

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee : public Person{
	public:
        Employee();
        Employee(std::string[5]);
		void setInfo(std::string, std::string, std::string, int, float);
		int getlvl() const;
		float getRate() const;
		std::string print() const;
	private:
		int lvl;
		float cPH;
};

Employee::Employee(){
	setInfo("", "", "", 0, 0.0);
}

Employee::Employee(std::string vars[5]){
    setInfo(vars[0], vars[1], vars[2], std::stoi(vars[3]), std::stof(vars[4]));
}

void Employee::setInfo(std::string f, std::string l, std::string id, int i, float cost){
	setName(f, l, id);
	lvl = i;
	cPH = cost;
}

int Employee::getlvl() const{
    return lvl;
}

float Employee::getRate() const{
    return cPH;
}

std::string Employee::print() const{
	return first + " " + last + " " + id;
}

#endif
