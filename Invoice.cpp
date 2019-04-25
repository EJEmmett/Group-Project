#include <sstream>
#include <iomanip>
#include "Customer.h"
#include "Invoice.h"

Invoice::Invoice(Customer _client, float tC, float tH) {
    client = _client;
    totalHours = tH;
    totalCost = tC;
}

std::string Invoice::print() {
    std::stringstream fC, fH;
    fH << std::fixed << std::setprecision(2) << totalHours;
    fC << std::fixed << std::setprecision(2) << totalCost;

    return "Customer: " + client.print() +
           "\nHours Worked: " + fH.str() +
           "\nTotal Cost: $" + fC.str() + "\n";
}
