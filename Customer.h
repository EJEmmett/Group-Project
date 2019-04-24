#include "Person.h"

#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer : public Person {
  public:
    Customer();
    Customer(std::string, std::string, std::string);
    Customer(std::string vars[7]);
    void setInfo(std::string, std::string, std::string);
    std::string print() const;
};

#endif
