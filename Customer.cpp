#include "Customer.h"

Customer::Customer() {
    setInfo("", "", "");
}

Customer::Customer(std::string u, std::string p, std::string id) {
    setInfo(u, p, id);
}

Customer::Customer(std::string vars[7]) {
    setInfo(vars[0], vars[2], vars[1]);
}

void Customer::setInfo(std::string u, std::string p, std::string id) {
    setName(u, p, id);
}

std::string Customer::print() const {
    return username + " " + id;
}
