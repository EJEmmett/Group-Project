#include <iostream>
#include "Repairs.h"

#ifndef LIST_H
#define LIST_H

template<typename T>
class List{
	public:
		List();
		void addNode(T);
        float sumCost();
		float sumHours();
		void printList();

	private:
		struct node{
			T data;
			node* next;
		};

		node* head;
		node* curr;
		node* temp;
};

template<typename T>
List<T>::List(){
	head = NULL;
	curr = NULL;
	temp = NULL;
}

template<typename T>
void List<T>::addNode(T dat){
	node* n = new node;
	n->next = NULL;
	n->data = dat;
	if(head){
		curr = head;
		while(curr->next)
			curr = curr->next;
		curr->next = n;
	}else
		head = n;
}

template<typename T>
void List<T>::printList(){
	curr = head;
	while(curr){
		std::cout << curr -> data << std::endl;
		curr = curr->next;
	}
}

template<>
float List<Repairs*>::sumCost(){
    float sum = 0;
	curr = head;
	while(curr){
        sum += curr->data->getHours() * curr->data->getEmployee().getRate();
		curr = curr->next;
	}
	return sum;
}

template<>
float List<Repairs*>::sumHours(){
    float sum = 0;
	curr = head;
	while(curr){
        sum += curr->data->getHours();
		curr = curr->next;
	}
	return sum;
}

template<>
void List<Repairs*>::printList(){
	curr = head;
	while(curr){
		std::cout << curr -> data -> print() << std::endl;
		curr = curr->next;
	}
}

#endif
