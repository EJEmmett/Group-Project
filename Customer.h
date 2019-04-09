#include <string>
#include "Person.h"

#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer : public Person{
	public:
        Customer();
		void setInfo(std::string, std::string, std::string, bool);
		std::string print() const;
	private:
		std::string cusID;
		//ticket : key
		//invoice : key
		bool flag;
};

Customer::Customer(){
	setInfo("", "", "", false);
}

void Customer::setInfo(std::string f, std::string l, std::string id, bool fl){
	setName(f, l);
	cusID = id;
	flag = fl;
}

std::string Customer::print() const{
	return first + " " + last + " " + cusID;
}

#endif
