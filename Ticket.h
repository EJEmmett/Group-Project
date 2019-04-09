#include "Invoice.h"
#include "Repairs.h"
#include <ctime>
#include <optional>

#ifndef TICKET_H
#define TICKET_H

class Ticket{
	public:
		Ticket(Customer, std::string);

		void addRepair(Employee, float, std::time_t, std::string); // int hoursWorked

		void listRepairs();
		std::string getCompletion() const;
		Customer getClient() const;
		std::string getStatus() const;
		Invoice getInvoice();

	private:
		std::time_t timeEntered;
		std::optional<std::time_t> timeCompleted;
		std::string status;
		List<Repairs*> repairsCompleted;
		Customer client;
		std::string equipment;
		std::optional<Invoice> invo;
};

Ticket::Ticket(Customer c, std::string e){
	client = c;
	equipment = e;
	timeEntered = std::time(nullptr);
	status = "Not Completed";
}

void Ticket::addRepair(Employee emp, float hoursWorked, std::time_t timeWorked, std::string workCompleted){
	repairsCompleted.addNode(new Repairs(emp, hoursWorked, timeWorked, workCompleted));
}

void Ticket::listRepairs(){
    repairsCompleted.printList();
}

std::string Ticket::getCompletion() const{
	return timeCompleted ? ctime(&*timeCompleted) : "Not Completed";
}

Customer Ticket::getClient() const{
	return client;
}

std::string Ticket::getStatus() const{
	return status;
}

Invoice Ticket::getInvoice(){
	if(!invo)
        invo = Invoice(client, repairsCompleted.sumCost(), repairsCompleted.sumHours());
    return *invo;
}

#endif
