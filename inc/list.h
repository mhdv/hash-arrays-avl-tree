#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>
#include <cstdlib>
#include "wezel.h"

template<typename T>
class MyNode;
template <typename T>

// opisy w pliku .cpp

class MyList{
public:
    MyList();
    ~MyList();
    bool empty();
    void displayList();
    void displayHead();
    void addFront(const T& e);
    bool findElement(T e);
    T removeFront();
private:
    MyNode<T>* head;
};


#endif // LIST_H
