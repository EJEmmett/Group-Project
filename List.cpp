#include "List.h"
#include <iostream>
#include "Repairs.h"
#include "Person.h"
#include "Ticket.h"

template<typename T>
List<T>::List() {
    head = NULL;
    curr = NULL;
    temp = NULL;
}

template<typename T>
List<T>::~List() {
    curr = head;
    while(curr) {
        temp = curr->next;
        delete curr;
        curr = temp;
    }
    delete head;
}

template<typename T>
void List<T>::addNode(T dat) {
    node* n = new node(dat);
    if(head) {
        curr = head;
        while(curr->next)
            curr = curr->next;
        curr->next = n;
    } else
        head = n;
}

template<typename T>
int List<T>::getPos() {
    curr = head;
    int count = 0;
    while(curr) {
        count++;
        curr = curr->next;
    }
    return count;
}

template<>
Person* List<Person*>::inList(std::string id) {
    curr = head;
    while(curr) {
        if(curr->data->getId() == id)
            return curr->data;
        else
            curr = curr->next;
    }
    return nullptr;
}

template<typename T>
typename List<T>::node* List<T>::getList() const {
    return head;
}

template<typename T>
void List<T>::printList() {
    curr = head;
    while(curr) {
        std::cout << curr -> data << std::endl;
        curr = curr->next;
    }
}

template<>
Person* List<Person*>::getNode(std::string u, std::string p) {
    curr = head;
    while(curr) {
        if(curr->data->compare(u, p))
            return curr->data;
        else
            curr = curr->next;
    }
    return nullptr;
}

template<>
float List<Repairs*>::sumCost() {
    float sum = 0;
    curr = head;
    while(curr) {
        sum += curr->data->getHours() * curr->data->getEmployee().getRate();
        curr = curr->next;
    }
    return sum;
}

template<>
float List<Repairs*>::sumHours() {
    float sum = 0;
    curr = head;
    while(curr) {
        sum += curr->data->getHours();
        curr = curr->next;
    }
    return sum;
}

template<>
void List<Repairs*>::printList() {
    curr = head;
    while(curr) {
        std::cout << curr -> data->print() << std::endl;
        curr = curr->next;
    }
}

template<>
void List<Ticket*>::printList() {
    curr = head;
    while(curr) {
        std::cout << curr -> data -> print() << std::endl;
        curr = curr->next;
    }
}

template class List<Person*>;
template class List<Repairs*>;
template class List<Ticket*>;
