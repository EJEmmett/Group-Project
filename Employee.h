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
			void setInfo(string, string, string, double);
			string print();
	private:
		string empID;
		double cPH;
};

#endif
