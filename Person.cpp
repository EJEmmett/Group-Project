#include <string>

#include "Person.h"

using namespace std;

Person::Person()
{
	setName("", "");
}

void Person::setName (string f, string l)
{
	first = f;
	last = l;
}
