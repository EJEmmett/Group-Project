#include "Ticket.h"

Ticket::Ticket(Customer c, std::string e){
	client = c;
	equipment = e;
	timeEntered = std::time(nullptr);
	status = "Not Completed";
	workHours = 0;
}
