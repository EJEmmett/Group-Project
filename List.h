#include <string>
#ifndef LIST_H
#define LIST_H

template<typename T>
class List {
  public:
    struct node {
        T data;
        node* next = nullptr;
        node(T dat) {
            data = dat;
        }
    };

    List();
    ~List();
    void addNode(T);
    int getPos();
    bool inList(T);
    float sumCost();
    float sumHours();
    node* getList() const;
    void printList();
    T getNode(std::string, std::string);

  private:
    node* head;
    node* curr;
    node* temp;
};

#endif
