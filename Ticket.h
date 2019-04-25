#include <iostream>
#include "Invoice.h"
#include "List.h"
#include "Repairs.h"

#ifndef TICKET_H
#define TICKET_H

class Ticket {
  public:
    Ticket();
    Ticket(Customer, std::string);

    void addRepair(Employee, float, double, std::string); // int hoursWorked
    List<Repairs>* getRepairs() const;


    virtual bool operator==(const Ticket& rhs) const{
        return false;
    }

    friend std::ostream& operator<<(std::ostream& os, const Ticket& obj);

    void listRepairs();
    std::string getCompletion() const;
    std::string getDescription() const;
    Customer getClient() const;
    std::string getStatus() const;
    Invoice getInvoice();

  private:
    double timeEntered;
    double timeCompleted;
    std::string status;
    List<Repairs>* repairsCompleted;
    Customer client;
    std::string description;
    Invoice* invo;
};

#endif
