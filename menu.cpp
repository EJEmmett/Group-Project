#include <iostream>
#include <ctime>

using namespace std;



int menu(){
	int choice;
	cout <<"\t\t\t\t\t\t       MENU   				     \n"	
		 <<"\t\t\t\t\t\t================ 				 \n"
    	 <<"\t\t\t\t\t1. Add new ticket 				 \n"
    	 <<"\t\t\t\t\t2. View ticket in progress		 \n"
    	 <<"\t\t\t\t\t3. Completed tickets				 \n"
    	 <<"\t\t\t\t\t4. Invoice						 \n"
    	 <<"\t\t\t\t\t5. Exit						 \n"
    	 <<"\t\t\t\tEnter your choice: ";

    cin >>choice;
    return(choice);
    
    
}
int main(int argc, char** argv) {
	
	int option;
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
	
}
