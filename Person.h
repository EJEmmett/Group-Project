#include <string>

#ifndef PERSON_H
#define PERSON_H

class Person{
	public:
        Person();
		void setName(std::string, std::string, std::string);
		std::string getId() const;
		bool compare(std::string, std::string) const;
        virtual bool operator==(const Person& rhs) const{
            return id == rhs.getId();
        }
		virtual std::string print() const = 0; //pure virtual for polymorphism
		std::string getUsername() const;
		std::string getPass() const;


	protected:
	    std::string username;
	    std::string password;
		std::string id;
};

#endif
