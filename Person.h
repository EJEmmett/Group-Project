//Person.h

#include <string>
using namespace std;

#ifndef PERSON_H
#define PERSON_H

class Person
{
	public:
			Person();
			void setName(string, string);
			virtual string print() = 0; //pure virtual for polymorphism
	protected:
		string first;
		string last;
};

Person::Person()
{
	setName("", "");
}

void Person::setName (string f, string l)
{
	first = f;
	last = l;
}

#endif
