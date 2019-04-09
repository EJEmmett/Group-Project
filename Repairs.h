#include "Employee.h"
#include <sstream>
#include <iomanip>

#ifndef REPAIRS_H
#define REPAIRS_H

class Repairs{
	public:
		Repairs(Employee, float, std::time_t, std::string);
		Employee getEmployee() const;
		float getHours() const;
		std::string print();

	private:
		Employee emp;
		float hoursWorked;
		std::time_t timeWorked;
		std::string workCompleted;
};

Repairs::Repairs(Employee _emp, float hW, std::time_t tW, std::string wC){
	emp = _emp;
	hoursWorked = hW;
	timeWorked = tW;
	workCompleted = wC;
}

Employee Repairs::getEmployee() const{
    return emp;
}

float Repairs::getHours() const{
    return hoursWorked;
}

std::string Repairs::print(){
	std::stringstream fHW;
	fHW << std::fixed << std::setprecision(2) << hoursWorked;

	return "Employee: " + emp.print() +
		   "\nTime Worked: " + std::string(ctime(&timeWorked)) +
		   "Work Completed: " + workCompleted +
		   "\nHours Worked: " + fHW.str() + "\n";
}

#endif
