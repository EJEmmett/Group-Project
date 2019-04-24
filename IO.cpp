#include <fstream>
#include <sstream>
#include <algorithm>
#include "List.h"
#include "Customer.h"

void load(List<Person*>& users){
	std::ifstream file("users.txt");
	std::string vars[5], line;
	while(getline(file, line)){
		std::stringstream ss(line);
		std::string word;
		int temp = 0;
		while(getline(ss, word, '|'))
			vars[temp++] = word;

		if(vars[2].find("cus") != std::string::npos)
            users.addNode(new Customer(vars));
		else
			users.addNode(new Employee(vars));
	}
	file.close();
}

void save(List<Person*>* users){
	std::ofstream file("human.txt", std::ios::trunc);

	auto curr = users->getList();
	while(curr){
        std::string id = curr->data->print();
		std::replace(id.begin(), id.end(), ' ', '|');
		std::string out = id;
	    if(auto data = dynamic_cast<Employee*>(curr->data)){
            std::stringstream e;
	        e << std::fixed << std::setprecision(2)
              << "|" << data->getlvl() << "|" << data->getRate();
            out += e.str();
	    }
        file << out << "\n";
        curr = curr->next;
	}
	file.close();
}
