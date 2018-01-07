#ifndef BINTREENODE_H
#define BINTREENODE_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <list>

template <typename T>
class MyBinTree;
template <typename T>
class MyBinTreeNode{
private:
    T element; // zawartosc elementu
    MyBinTreeNode<T>* left; // lewy syn
    MyBinTreeNode<T>* right; // prawy syn
    friend class MyBinTree<T>;

public:

    T getElement() {return element;}

    MyBinTreeNode<T>* getLeft() {return left;} // zwraca lewego syna
    MyBinTreeNode<T>* getRight() {return right;} // zwraca prawego syna
    void setLeft(MyBinTreeNode<T>* tmp) {left=tmp;}
    void setRight(MyBinTreeNode<T>* tmp) {right=tmp;}

    void setElement(T newE) {element=newE;} // ustala element
};

#endif