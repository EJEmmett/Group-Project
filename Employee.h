//Employee.h

#include "Person.h"
#include <string>
using namespace std;

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee : public Person
{
	public:
			Employee();
			void setInfo(string, string, string, int, double);
			string print();
	private:
		string empID;
		int lvl;
		double cPH;
};

Employee::Employee()
{
	setInfo("", "", "", 0, 0.0);
}

void Employee::setInfo(string f, string l, string id, int i, double cost)
{
	setName(f, l);
	empID = id;
	lvl = i;
	cPH = cost;
}

string Employee::print()
{
	return first + " " + last + " " + empID;
}

#endif
