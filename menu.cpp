#include <iostream>
#include <ctime>
//#include "invoice.cpp"


using namespace std;



int menu(){
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

int customerMenu(){
	int choice;
	cout <<"\t\t\t\t\t\t  CUSTOMER MENU   			 \n"	
		 <<"\t\t\t\t\t\t================ 			 \n"
    	 <<"\t\t\t\t\t1. Add new ticket 			 \n"
    	 <<"\t\t\t\t\t2. Exit						 \n"
    	 <<"\t\t\t\tEnter your choice: ";

    cin >>choice;
    return(choice);    
}

int employeeMenu(){
	int choice;
	cout <<"\t\t\t\t\t\t  EMPLOYEE MENU   				 \n"	
		 <<"\t\t\t\t\t\t================ 				 \n"
    	 <<"\t\t\t\t\t1. View ticket in progress 		 \n"
    	 <<"\t\t\t\t\t2. Exit							 \n"
    	 <<"\t\t\t\tEnter your choice: ";

    cin >>choice;
    return(choice);    
}

int ticketMenu(){
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

int managerMenu(){
	int choice;
	cout <<"\t\t\t\t\t\t  MANAGER MENU   				 \n"	
		 <<"\t\t\t\t\t\t================ 				 \n"
    	 <<"\t\t\t\t\t1. Add new ticket 				 \n"
    	 <<"\t\t\t\t\t5. Exit							 \n"
    	 <<"\t\t\t\tEnter your choice: ";

    cin >>choice;
    return(choice);
    
    
}

void cusMenu(){
	int option;
	string name;
	string currName;
	string comment;
	time_t now;
	struct tm nowLocal;
	now=time(NULL);
	nowLocal=*localtime(&now);
					do {
						option = customerMenu();
						switch(option){
							  
							case 1: system("CLS");
							cout<<"What is your name? "<<endl;
							cin>>name;
							cout<<"What is the ticket for? "<<endl;
							cin>>comment;
							cout<<name<<" entered a ticket on "<<nowLocal.tm_mon+1<<"/"<<nowLocal.tm_mday<<"/"<<nowLocal.tm_year+1900<<" at "<<nowLocal.tm_hour<<":"<<nowLocal.tm_min<<":"<<nowLocal.tm_sec<<endl;
							cout<<"Description: "<<comment<<endl;
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
		switch(option){
			case 1:
				//for(int i;i<totTicket;i++){
				//	cout<<ticket(i)<<endl;
				//}
			break;
			case 2:
				system("CLS");
				cout<<"Bye"<<endl;
			break;
		}
	} while (option !=2);
}

void empMenu() {
	int option;
	do {
		option = employeeMenu();
		switch(option){
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
		switch(option){
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
	
	int option;
	do {
		option = menu();
		switch(option){
			
					case 1: system("CLS");
					cusMenu();
					break;
					case 2: system("CLS");
					empMenu();
					break;
					case 3: system("CLS");
					manMenu();
					break;
					case 4: system("CLS");
					cout<<"BYE!!"<<endl;
					break;
				}
	}while (option != 4);
}


	/*
	string name;
	string currName;
	string comment;
	time_t now;
	struct tm nowLocal;
	now=time(NULL);
	nowLocal=*localtime(&now);
	do {
		option = menu();
		switch(option){
			
					case 1: cout<<"Please enter your name: "<<endl;
							cin>>name;
							cout<<"What is the ticket for: "<<endl;
							cin>>comment;
							cout<<name<<" entered a ticket on "<<nowLocal.tm_mon+1<<"/"<<nowLocal.tm_mday<<"/"<<nowLocal.tm_year+1900<<" at "<<nowLocal.tm_hour<<":"<<nowLocal.tm_min<<":"<<nowLocal.tm_sec<<endl;
							cout<<"Description: "<<comment<<endl;
					break;					
					case 2: cout<<"What is the name on the ticket:"<<endl;
							cin>>currName;
							for(int i; i<totTicket; i++){
								if(totTicket.name == currName){
									cout<<"The ticket under this name is: "<<ticket(i)<<endl;
								} 
							}
					break;					
					case 3: for(int i; i<totTicket; i++){
								cout<<ticket(i)<<endl;
							}
					break;			
					break;
					case 4:cout<<"What is the name on the invoice: "<<endl;
							cin<<currName;
							for(int i; i<totInvoice; i++){
								if(totInvoice.name == currName){
									cout<<"The invoice under this name is: "<<invoice(i)<<endl;
								} 
							}
					break;
					case 5:
						cout<<"Bye!!";
					break;
					
					default: cout<<option<<" is an invalid option!\n";
		}
	}while (option != 4);
	*/
	

