#include <sstream>
#include <iomanip>
#include <iostream>
#include "Employee.h"

#ifndef REPAIRS_H
#define REPAIRS_H

class Repairs {
  public:
    Repairs(Employee, float, std::time_t, std::string);
    Employee getEmployee() const;
    float getHours() const;
    std::string print();

    virtual bool operator==(const Repairs& rhs) const{
        return false;
    }

    friend std::ostream& operator<<(std::ostream& os, const Repairs& r);

  private:
    Employee emp;
    float hoursWorked;
    std::time_t timeWorked;
    std::string workCompleted;
};

#endif
