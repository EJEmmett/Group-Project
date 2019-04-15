#include <string>
#include "Person.h"

#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer : public Person{
	public:
        Customer();
        Customer(std::string vars[5]);
		void setInfo(std::string, std::string, std::string);
		std::string print() const;
};

Customer::Customer(){
	setInfo("", "", "");
}

Customer::Customer(std::string vars[5]){
    setInfo(vars[0], vars[1], vars[2]);
}

void Customer::setInfo(std::string f, std::string l, std::string id){
	setName(f, l, id);
}

std::string Customer::print() const{
	return first + " " + last + " " + id;
}

#endif
