#include "Person.h"

Person::Person(){
	setName("", "", "");
}

std::string Person::getId() const{
    return id;
}

bool Person::compare(std::string u, std::string p) const{
    return (username==u && password==p);
}

void Person::setName(std::string u, std::string p, std::string _id){
	username = u;
	password = p;
	id = _id;
}

std::string Person::getPass() const{
	return password;
}
