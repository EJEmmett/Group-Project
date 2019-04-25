#include <iostream>
#include <fstream>
#include <algorithm>
#include "Customer.h"
#include "Employee.h"
#include "Ticket.h"

using namespace std;

void loadUsers(List<Person*>* users) {
    ifstream file("users.txt");
    if(!file)
        return;

    string vars[5], line;
    while(getline(file, line)) {
        stringstream ss(line);
        string word;
        int temp = 0;
        while(getline(ss, word, '|'))
            vars[temp++] = word;

        if(vars[1].find("Cus") != string::npos)
            users->addNode(new Customer(vars));
        else
            users->addNode(new Employee(vars));
    }
    file.close();
}

void saveUsers(List<Person*>* users) {
    ofstream file("users.txt", ios::trunc);

    auto curr = users->getList();
    while(curr) {
        string id = curr->data->print();
        replace(id.begin(), id.end(), ' ', '|');
        file << id << "|" << curr->data->getPass() << "|" << "\n";
        curr = curr->next;
    }
    file.close();
}

void loadTickets(List<Ticket*>* tickets, List<Person*>* users) {
    ifstream file("tickets.txt");
    if(!file)
        return;
    string vars[7], line;
    while(getline(file, line)) {
        stringstream ss(line);
        string word;
        int temp = 0;
        while(getline(ss, word, '|'))
            vars[temp++] =  word;
        Ticket* t = new Ticket(*dynamic_cast<Customer*>(users->inList(vars[0])), vars[1]);

        stringstream ss2(vars[2]);
        string individuals;
        temp = 0;
        while(getline(ss2, individuals, ']')){
            stringstream ss3(individuals);
            string repairItems;
            temp = 0;
            while(getline(ss3, repairItems, '\\'))
                vars[temp++] = repairItems;
            t->addRepair(new Employee(vars), stoi(vars[4]), stof(vars[5]), vars[6]);
        }

        tickets->addNode(t);
    }
    file.close();
}

void saveTickets(List<Ticket*>* tickets) {
    ofstream file("tickets.txt", ios::trunc);

    auto curr = tickets->getList();
    while(curr) {
        Ticket* t = curr->data;
        string fin = t->getClient().getId() + "|" + t->getDescription();
        string re = "";
        auto repair = t->getRepairs().getList();
        while(repair){
            string items = repair->data->getRep();
            replace(items.begin(), items.end(), ' ', '/');
            re += items + "]";
            repair = repair->next;
        }
        fin += "|" + re + "\n";
        file << fin;
        curr = curr->next;
    }
    file.close();
}

Person* login(List<Person*>* users) {
    string username;
    string password;
    cout << "Username: " << endl;
    cin.clear();
    fflush(stdin);
    getline(cin, username);
    cout<<"Password: "<<endl;
    getline(cin, password);
    return users->getNode(username, password);
}

Person* create(List<Person*>* users) {
    int acctType;
    string username;
    string password;
    cout << "Username: ";
    cin.clear();
    fflush(stdin);
    getline(cin, username);
    cout<<"Password: ";
    getline(cin, password);
    cout<<"Account Type: \n"
        <<"1. Customer \n"
        <<"2. Employee \n"
        <<"Enter Here: ";
    cin >> acctType;
    Person* user;
    if(acctType == 1)
        user = new Customer(username, password, string("Cus"+to_string(users->getPos())));
    else{
        int grade;
        float rate;
        cout<<"Pay Rate: ";
        cin >> rate;
        cout<<"Grade: ";
        cin >> grade;
        user = new Employee(username, password, string("Emp"+to_string(users->getPos())), grade, rate);
    }
    users->addNode(user);
    saveUsers(users);
    return user;
}

int loginMenu() {
    int choice;
    system("cls");
    cout <<"\t\t\t\t\t\t       MENU   				     \n"
         <<"\t\t\t\t\t\t================ 				 \n"
         <<"\t\t\t\t\t1. Login 				             \n"
         <<"\t\t\t\t\t2. Create Account                  \n"
         <<"\t\t\t\t\t3. Exit							 \n"
         <<"\t\t\t\tEnter your choice: ";
    cin >>choice;
    return choice;
}

int customerMenu() {
    int choice;
    cout <<"\t\t\t\t\t\t  CUSTOMER MENU   			 \n"
         <<"\t\t\t\t\t\t================ 			 \n"
         <<"\t\t\t\t\t1. Add new ticket 			 \n"
         <<"\t\t\t\t\t2. Exit						 \n"
         <<"\t\t\t\tEnter your choice: ";

    cin >>choice;
    return(choice);
}

int employeeMenu() {
    int choice;
    cout <<"\t\t\t\t\t\t  EMPLOYEE MENU   				 \n"
         <<"\t\t\t\t\t\t================ 				 \n"
         <<"\t\t\t\t\t1. View ticket in progress 		 \n"
         <<"\t\t\t\t\t2. Exit							 \n"
         <<"\t\t\t\tEnter your choice: ";

    cin >>choice;
    return(choice);
}

int ticketMenu() {
    int choice;
    cout <<"\t\t\t\t\t\t  TICKET MENU   				 \n"
         <<"\t\t\t\t\t\t================ 				 \n"
         <<"\t\t\t\t\t1. View all tickets				 \n"
         <<"\t\t\t\t\t2. Add Repair						 \n"
         <<"\t\t\t\t\t3. Exit							 \n"
         <<"\t\t\t\tEnter your choice: ";

    cin >>choice;
    return(choice);
}

void cusMenu(Customer* currUser, List<Ticket*>* tickets) {
    int option;
    string name;
    string currName;
    string comment;
    do {
        option = customerMenu();
        switch(option) {
        case 1:
            system("CLS");
            cin.clear();
            fflush(stdin);
            cout<<"What is the ticket for? ";
            getline(cin, comment);
            cout<<"Ticket Processed."<<endl;
            tickets->addNode(new Ticket(*currUser, comment));
            saveTickets(tickets);
            break;
        case 2:
            cout<<"Bye"<<endl;
            break;
        }
    } while (option !=2);
}

void repairMenu(Person* currUser, List<Ticket*>* tickets){
    cout << "Ticket Number:" << endl;
    tickets->printList();
    int option;
    float hW;
    double tW;
    std::string wC;
    cout << "Enter here: ";
    cin >> option;
    Ticket* t = tickets->getNode(option-1);
    cout << "Hours Worked: ";
    cin >> hW;
    cout << "Time Worked: ";
    cin >> tW;
    cout << "Work Completed: ";
    cin.clear();
    fflush(stdin);
    getline(cin, wC);
    t->addRepair(dynamic_cast<Employee*>(currUser), hW, tW, wC);
    tickets->setNode(option-1, t);
}

void ticMenu(Person* currUser, List<Ticket*>* tickets) {
    int option;
    do {
        option = ticketMenu();
        switch(option) {
        case 1:
            tickets->printList();
            break;
        case 2:
            repairMenu(currUser, tickets);
            break;
        case 3:
            system("CLS");
            cout<<"Bye"<<endl;
            break;
        }
    } while (option !=3);
}

void empMenu(Person* currUser, List<Ticket*>* tickets) {
    int option;
    do {
        option = employeeMenu();
        switch(option) {
            case 1:
                ticMenu(currUser, tickets);
                break;
            case 2:
                system("CLS");
                cout<<"Bye"<<endl;
                break;
        }
    } while (option !=3);
}

int main(int argc, char** argv) {
    List<Person*> users;
    List<Ticket*> tickets;
    loadUsers(&users);
    loadTickets(&tickets, &users);
    Person* currentUser = nullptr;
    int option;
    do {
        system("CLS");
        option = loginMenu();
        system("CLS");
        switch(option) {
        case 1:
            if(Person* temp = login(&users))
                currentUser = temp;
            else {
                cout << "User not found.";
                system("pause");
            }
            break;
        case 2:
            currentUser = create(&users);
            break;
        case 3:
            cout<<"BYE!!"<<endl;
            break;
        }
    } while (option != 3 && !currentUser);

    if(option == 3)
        return 0;

    if(auto temp = dynamic_cast<Customer*>(currentUser))
        cusMenu(temp, &tickets);
    else
        empMenu(currentUser, &tickets);
}


