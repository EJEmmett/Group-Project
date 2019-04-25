#include "Ticket.h"
#include "Repairs.h"
#include "Invoice.h"
#include "List.h"

Ticket::Ticket() {
    client = nullptr;
    description = "";
    timeEntered = 0;
    status = "Not Completed";
    invo = nullptr;
}

Ticket::Ticket(Customer c, std::string d) {
    client = c;
    description = d;
    timeEntered = 0;
    status = "Not Completed";
}

void Ticket::addRepair(Employee* emp, float hoursWorked, double timeWorked, std::string workCompleted) {
    repairsCompleted.addNode(new Repairs(emp, hoursWorked, timeWorked, workCompleted));
}

List<Repairs*> Ticket::getRepairs() const{
    return repairsCompleted;
}

void Ticket::listRepairs() {
    repairsCompleted.printList();
}

std::string Ticket::getCompletion() const {
    return timeCompleted ? std::to_string(timeCompleted) : "Not Completed";
}

Customer Ticket::getClient() const {
    return client;
}

std::string Ticket::getStatus() const {
    return status;
}

std::string Ticket::getDescription() const{
    return description;
}

std::string Ticket::print() const{
    return "Username: " + client.getUsername() + "\nDescription: " + description;
}

Invoice Ticket::getInvoice() {
    if(!invo)
        invo = new Invoice(client, repairsCompleted.sumCost(), repairsCompleted.sumHours());
    return *invo;
}

std::ostream& operator<<(std::ostream& os, const Ticket& obj){
    return os;
}
