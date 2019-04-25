#include <iostream>
#include <ctime>
#include"Ticket.h"
//#include "invoice.cpp"


using namespace std;

Person* login(List<Person*>& users) {
    string username;
    string password;
    cout << "Username: " << endl;
    cin.clear();
    fflush(stdin);
    getline(cin, username);
    cout<<"Password: "<<endl;
    getline(cin, password);
    return users.getNode(username, password);
}

Person* create(List<Person*>& users) {
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
        user = new Customer(username, password, string("Cus"+users.getPos()));
    else{
        int grade;
        float rate;
        cout<<"Pay Rate: ";
        cin >> rate;
        cout<<"Grade: ";
        cin >> grade;
        user = new Employee(username, password, string("Emp"+users.getPos()), grade, rate);
    }
    users.addNode(user);

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

int menu() {
    int choice;
    cout <<"\t\t\t\t\t\t       MENU   				     \n"
         <<"\t\t\t\t\t\t================ 				 \n"
         <<"\t\t\t\t\t1. I am a customer 				 \n"
         <<"\t\t\t\t\t2. I am an employee     			 \n"
         <<"\t\t\t\t\t3. I am a manager					 \n"
         <<"\t\t\t\t\t4. Exit							 \n"
         <<"\t\t\t\tEnter your choice: ";

    cin >>choice;
    return(choice);
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
         <<"\t\t\t\t\t1. Veiw all tickets				 \n"
         <<"\t\t\t\t\t1. Add Repair						 \n"
         <<"\t\t\t\t\t2. Exit							 \n"
         <<"\t\t\t\tEnter your choice: ";

    cin >>choice;
    return(choice);
}

int managerMenu() {
    int choice;
    cout <<"\t\t\t\t\t\t  MANAGER MENU   				 \n"
         <<"\t\t\t\t\t\t================ 				 \n"
         <<"\t\t\t\t\t1. Add new ticket 				 \n"
         <<"\t\t\t\t\t2. Exit							 \n"
         <<"\t\t\t\tEnter your choice: ";

    cin >>choice;
    return(choice);
}

void cusMenu(Customer currUser, List<Ticket>& tickets) {
    int option;
    string name;
    string currName;
    string comment;
    do {
        option = customerMenu();
        switch(option) {
        case 1:
            system("CLS");
            cout << "What is your name? " << endl;
            cin.clear();
            fflush(stdin);
            getline(cin, name);
            cout<<"What is the ticket for? "<<endl;
            getline(cin, comment);
            cout<<"Ticket Processed."<<endl;
            tickets.addNode(Ticket(currUser, comment));
            break;
        case 2:
            cout<<"Bye"<<endl;
            break;
        }
    } while (option !=2);
}

void ticMenu() {
    int option;
    do {
        option = ticketMenu();
        switch(option) {
        case 1:
            //for(int i;i<totTicket;i++){
            //  cout<<ticket(i)<<endl;
            //}
            break;
        case 2:
            system("CLS");
            cout<<"Bye"<<endl;
            break;
        }
    } while (option !=2);
}

void empMenu(Person* currUser, List<Ticket>& tickets) {
    int option;
    do {
        option = employeeMenu();
        switch(option) {
        case 1:

            break;
        case 2:
            system("CLS");
            cout<<"Bye"<<endl;
            break;
        }
    } while (option !=2);
}

void manMenu() {
    int option;
    do {
        option = managerMenu();
        switch(option) {
        case 1:

            break;
        case 2:
            system("CLS");
            cout<<"Bye"<<endl;
            break;
        }
    } while (option !=2);
}

int main(int argc, char** argv) {
    List<Person*> users;
    List<Ticket> tickets;
    Person* currentUser = nullptr;
    int option;
    do {
        system("CLS");
        option = loginMenu();
        system("CLS");
        switch(option) {
        case 1:
            if(Person* temp = login(users))
                currentUser = temp;
            else {
                cout << "User not found.";
                system("pause");
            }
            break;
        case 2:
            currentUser = create(users);
            break;
        case 3:
            cout<<"BYE!!"<<endl;
            break;
        }
    } while (option != 3 && !currentUser);

    if(option == 3)
        return 0;

    if(auto temp = dynamic_cast<Customer*>(currentUser))
        cusMenu(*temp, tickets);
    else
        empMenu(currentUser, tickets);

}


