#include <ctime>
#include <optional>
#include "Invoice.h"
#include "List.h"
#include "Repairs.h"

#ifndef TICKET_H
#define TICKET_H

class Ticket {
  public:
    Ticket();
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
    std::string description;
    std::optional<Invoice> invo;
};

#endif
