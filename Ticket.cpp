#include "Ticket.h"
#include "Repairs.h"
#include "Invoice.h"
#include "List.h"

Ticket::Ticket() {
    client = nullptr;
    description = "";
    timeEntered = std::time(nullptr);
    status = "Not Completed";
}

Ticket::Ticket(Customer c, std::string d) {
    client = c;
    description = d;
    timeEntered = std::time(nullptr);
    status = "Not Completed";
}

void Ticket::addRepair(Employee emp, float hoursWorked, std::time_t timeWorked, std::string workCompleted) {
    repairsCompleted.addNode(new Repairs(emp, hoursWorked, timeWorked, workCompleted));
}

void Ticket::listRepairs() {
    repairsCompleted.printList();
}

std::string Ticket::getCompletion() const {
    return timeCompleted ? ctime(&*timeCompleted) : "Not Completed";
}

Customer Ticket::getClient() const {
    return client;
}

std::string Ticket::getStatus() const {
    return status;
}

Invoice Ticket::getInvoice() {
    if(!invo)
        invo = Invoice(client, repairsCompleted.sumCost(), repairsCompleted.sumHours());
    return *invo;
}
