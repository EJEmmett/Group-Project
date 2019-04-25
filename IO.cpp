#include <fstream>
#include <algorithm>
#include "Customer.h"
#include "Employee.h"
#include "Ticket.h"

void loadUsers(List<Person*>* users) {
    std::ifstream file("users.txt");
    std::string vars[5], line;
    while(getline(file, line)) {
        std::stringstream ss(line);
        std::string word;
        int temp = 0;
        while(getline(ss, word, '|'))
            vars[temp++] = word;

        if(vars[2].find("cus") != std::string::npos)
            users->addNode(new Customer(vars));
        else
            users->addNode(new Employee(vars));
    }
    file.close();
}

void saveUsers(List<Person*>* users) {
    std::ofstream file("users.txt", std::ios::trunc);

    auto curr = users->getList();
    while(curr) {
        std::string id = curr->data->print();
        std::replace(id.begin(), id.end(), ' ', '|');
        file << id << "\n";
        curr = curr->next;
    }
    file.close();
}

void loadTickets(List<Ticket>* tickets, List<Person*>* users) {
    std::ifstream file("tickets.txt");

    std::string vars[7], line;
    while(getline(file, line)) {
        std::stringstream ss(line);
        std::string word;
        int temp = 0;
        while(getline(ss, word, '|'))
            vars[temp++] = word;
        Ticket t = Ticket(*dynamic_cast<Customer*>(users->inList(vars[0])), vars[1]);

        std::stringstream ss2(word);
        std::string individuals;
        temp = 0;
        while(getline(ss2, individuals, ']')){
            std::stringstream ss3(individuals);
            std::string repairItems;
            temp = 0;
            while(getline(ss3, repairItems, '\\'))
                vars[temp++] = repairItems;
            t.addRepair(Employee(vars), std::stoi(vars[4]), std::stof(vars[5]), vars[6]);
        }

        tickets->addNode(t);
    }
    file.close();
}

void saveTickets(List<Ticket>* tickets) {
    std::ofstream file("tickets.txt", std::ios::trunc);

    auto curr = tickets->getList();
    while(curr) {
        Ticket t = curr->data;
        std::string fin = t.getClient().getId() + "|" + t.getDescription();
        std::string re = "";
        auto repair = t.getRepairs()->getList();
        while(repair){
            std::string items = repair->data.getRep();
            std::replace(items.begin(), items.end(), ' ', '/');
            re += items + "]";
        }
        fin += "]" + re + "\n";
        file << fin;
    }
    file.close();
}

