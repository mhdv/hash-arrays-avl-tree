#ifndef WEZEL_H
#define WEZEL_H

#include <iostream>
#include <string>
#include <cstdlib>

template <typename T>
class MyList;
template <typename T>
class MyNode{
private:
    T element; // zawartosc elementu
    MyNode<T>* next; // wskaznik na nastepny element
    friend class MyList<T>; // lista zaprzyjaznionych klas
public:
    T getElement() {return element;} // zwraca element
    MyNode<T>* getNext() {return next;} // zwraca next
    void setElement(T newE) {element=newE;} // ustala element
    void setNext(MyNode<T> newN) {next=newN;} // ustala next
};


#endif // WEZEL_H
