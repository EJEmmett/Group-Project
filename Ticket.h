#include "Customer.h"
#include "Invoice.h"
#include <ctime>

class Ticket{
	public:
		Ticket(Customer, std::string);
		
		void addRepair(Technician, int) // int hoursWorked
		
		std::string getStatus();
		void listRepairs();
		std::time_t getCompletion();
		Customer getClient();
		Invoice getInvoice();
		
	private:
		std::time_t timeEntered;
		std::time_t timeCompleted;
		std::string status;
		List<Technician, int, std::time_t, std::string> repairsCompleted;
		int workHours;
		Customer client;
		std::string equipment;
		Invoice invo;
};
