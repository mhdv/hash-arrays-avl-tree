#include <iostream>
#include <string>
#include <cstdlib>
#include "list.h"


template<typename T>
MyList<T>::MyList() // konstruktor
    :head(NULL)    {}

template<typename T>
MyList<T>::~MyList() // destruktor
    {}

// DODAJE ELEMENT

template<typename T>
void MyList<T>::addFront(const T &e){
    MyNode<T>* v = new MyNode<T>; // tworzy wezel
    v->element = e; // instrukcje ustalajace kazdy nowy element na head
    v->next = head;
    head = v;
}

// USUWA ELEMENT GLOWY

template<typename T>
T MyList<T>::removeFront(){
    MyNode<T>* old = head; // wezel pomocniczy
    T tmp = head->getElement();
    head = old->next;
    delete old; // usuwanie wezla pomocniczego
    return tmp;
}

// ZWRACA PRAWDE JESLI LISTA JEST PUSTA

template<typename T>
bool MyList<T>::empty(){ // funkcja zwracajaca prawde jesli lista jest pusta
    if(head==NULL) return true;
    else return false;
}

// WYSWIETLA GLOWE LISTY

template<typename T>
void MyList<T>::displayHead(){ // wyswietla head
    std::cout << head->getElement();
    std::cout << "\n";
}

// WYSWIETLA CALA ZAWARTOSC LISTY

template<typename T>
void MyList<T>::displayList(){ // wyswietla cala liste
    MyNode<T>* tmp = new MyNode<T>; // tworzy wezel pomocniczy
    tmp=head; // ustawia wezel pomocniczy na head naszej listy
    do{
        std::cout << tmp->getElement();
        tmp=tmp->getNext();
        std::cout << " ";
    }while(tmp!=nullptr);
    delete tmp; // usuwa wezel pomocniczy
}

template <typename T>
bool MyList<T>::findElement(T e){
    MyNode<T>* tmp = new MyNode<T>;
    tmp=head;
    if(!empty())
    do{
        if(tmp->getElement()==e) return true;
        tmp=tmp->getNext();
    }while(tmp!=nullptr);
    return false;
}

//########################
template class MyList<int>;
template class MyList<double>;
template class MyList<float>;
template class MyList<std::string>;
