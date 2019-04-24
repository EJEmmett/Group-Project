#include "Repairs.h"

Repairs::Repairs(Employee _emp, float hW, std::time_t tW, std::string wC) {
    emp = _emp;
    hoursWorked = hW;
    timeWorked = tW;
    workCompleted = wC;
}

Employee Repairs::getEmployee() const {
    return emp;
}

float Repairs::getHours() const {
    return hoursWorked;
}

std::string Repairs::print() {
    std::stringstream fHW;
    fHW << std::fixed << std::setprecision(2) << hoursWorked;

    return "Employee: " + emp.print() +
           "\nTime Worked: " + std::string(ctime(&timeWorked)) +
           "Work Completed: " + workCompleted +
           "\nHours Worked: " + fHW.str() + "\n";
}