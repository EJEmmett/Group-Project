#include <sstream>
#include <iomanip>
#include <iostream>
#include "Employee.h"

#ifndef REPAIRS_H
#define REPAIRS_H

class Repairs {
  public:
    Repairs();
    Repairs(Employee*, float, double, std::string);
    Employee* getEmployee() const;
    float getHours() const;
    std::string print();
    std::string getRep() const;

    virtual bool operator==(const Repairs& rhs) const{
        return false;
    }

    friend std::ostream& operator<<(std::ostream& os, const Repairs& r);

  private:
    Employee* emp;
    float hoursWorked;
    double timeWorked;
    std::string workCompleted;
};

#endif
