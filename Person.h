#include <string>

#ifndef PERSON_H
#define PERSON_H

class Person{
	public:
        Person();
		void setName(std::string, std::string);
		virtual std::string print() const = 0; //pure virtual for polymorphism
	protected:
		std::string first;
		std::string last;
};

Person::Person(){
	setName("", "");
}

void Person::setName(std::string f, std::string l){
	first = f;
	last = l;
}

#endif
