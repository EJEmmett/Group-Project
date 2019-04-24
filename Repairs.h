#include <sstream>
#include <iomanip>
#include "Employee.h"

#ifndef REPAIRS_H
#define REPAIRS_H

class Repairs {
  public:
    Repairs(Employee, float, std::time_t, std::string);
    Employee getEmployee() const;
    float getHours() const;
    std::string print();

  private:
    Employee emp;
    float hoursWorked;
    std::time_t timeWorked;
    std::string workCompleted;
};

#endif
