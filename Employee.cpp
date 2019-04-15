#include "Person.h"
#include <string>

#include "Employee.h"

using namespace std;

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
