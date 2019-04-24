#include "Customer.h"
#include <sstream>
#include <iomanip>

#ifndef INVOICE_H
#define INVOICE_H

class Invoice{
	public:
		Invoice(Customer, float, float);
		std::string print();

	private:
	    Customer client;
	    float totalHours;
		float totalCost;
};

Invoice::Invoice(Customer _client, float tC, float tH){
    client = _client;
    totalHours = tH;
	totalCost = tC;
}

std::string Invoice::print(){
	std::stringstream fC, fH;
    fH << std::fixed << std::setprecision(2) << totalHours;
	fC << std::fixed << std::setprecision(2) << totalCost;

	return "Customer: " + client.print() +
		   "\nHours Worked: " + fH.str() +
		   "\nTotal Cost: $" + fC.str() + "\n";
}

#endif
