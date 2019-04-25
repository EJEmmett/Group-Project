#include "Employee.h"

Employee::Employee() {
    setInfo("", "", "", 0, 0.0);
}

Employee::Employee(std::string vars[7]) {
    setInfo(vars[0], vars[1], vars[2], std::stoi(vars[3]), std::stof(vars[4]));
}

Employee::Employee(std::string u, std::string p, std::string id, int i, float cost) {
    setInfo(u, p, id, i, cost);
}

void Employee::setInfo(std::string u, std::string p, std::string id, int i, float cost) {
    setName(u, p, id);
    lvl = i;
    cPH = cost;
}

int Employee::getlvl() const {
    return lvl;
}

float Employee::getRate() const {
    return cPH;
}

std::string Employee::print() const {
    std::stringstream e;
    e << std::fixed << std::setprecision(2)
      << username << " " << id <<  " " << lvl << " " << cPH;

    return e.str();
}
