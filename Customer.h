//Customer.h

#include "Person.h"
#include <string>
using namespace std;

#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer : public Person
{
	public:
			Customer();
			void setInfo(string, string, string, bool);
			string print();
	private:
		string cusID;
		//ticket : key
		//invoice : key
		boolean flag;
};

Customer::Customer()
{
	setInfo("", "", "", false);
}

void Customer::setInfo(string f, string l, string id, bool fl)
{
	setName(f, l);
	cusID = id;
	flag = fl;
}

string Customer::print()
{
	return first + " " + last + " " + cusID;
}

#endif
