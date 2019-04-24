#include "Customer.h"

#ifndef INVOICE_H
#define INVOICE_H

class Invoice {
  public:
    Invoice(Customer, float, float);
    std::string print();

  private:
    Customer client;
    float totalHours;
    float totalCost;
};

#endif
