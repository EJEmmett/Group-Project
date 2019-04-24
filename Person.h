#include <string>

#ifndef PERSON_H
#define PERSON_H

class Person{
	public:
        Person();
		void setName(std::string, std::string, std::string);
		std::string getId() const;
		bool compare(std::string, std::string) const;
        virtual bool operator==(const Person& rhs) const{
            return id == rhs.getId();
        }
		virtual std::string print() const = 0; //pure virtual for polymorphism
	protected:
	    std::string username;
	    std::string password;
		std::string first;
		std::string last;
		std::string id;
};

Person::Person(){
	setName("", "", "");
}

std::string Person::getId() const{
    return id;
}

bool Person::compare(std::string u, std::string p) const{
    return (username==u && password==p);
}

void Person::setName(std::string f, std::string l, std::string _id){
	first = f;
	last = l;
	id = _id;
}

#endif
