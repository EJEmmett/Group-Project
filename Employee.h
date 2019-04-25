#include <sstream>
#include <iomanip>
#include "Person.h"

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee : public Person {
  public:
    Employee();
    Employee(std::string[7]);
    Employee(std::string, std::string, std::string, int, float);
    void setInfo(std::string, std::string, std::string, int, float);
    int getlvl() const;
    float getRate() const;
    std::string print() const;
  private:
    int lvl;
    float cPH;
};

#endif
