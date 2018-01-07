#ifndef BINTREE_H
#define BINTREE_H

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>

#include "bintreenode.h"

// dokladne opisy metod w pliku .cpp

template <typename T>
class MyBinTree{
private:
	int size;	// rozmiar drzewa
	MyBinTreeNode<T>* root; // korzen drzewa
public:
	MyBinTree(); // konstruktor
	~MyBinTree(); // destruktor 

	MyBinTreeNode<T>* getRoot(){return root;} // zwraca korzen
	MyBinTreeNode<T>* add(MyBinTreeNode<T>* node, T elem); // dodaje element
	MyBinTreeNode<T>* llrotate(MyBinTreeNode<T>* node);	// rotacje
	MyBinTreeNode<T>* rrrotate(MyBinTreeNode<T>* node);
	MyBinTreeNode<T>* lrrotate(MyBinTreeNode<T>* node);
	MyBinTreeNode<T>* rlrotate(MyBinTreeNode<T>* node);
	MyBinTreeNode<T>* balance(MyBinTreeNode<T>* node);	// funkcja rownowazaca drzewo

	void remove(MyBinTreeNode<T>* node, T elem); // usuwa element
	int getHeight(MyBinTreeNode<T>* start); // zwraca wysokosc drzewa od wskazanego wezla (domyslnie powinien byc root)
	int getDifference(MyBinTreeNode<T>* start); // zwraca roznice wysokosci

	void display(MyBinTreeNode<T>* start, int level); // wyswietla zawartosc drzewa (niekonieczne, ale przydatne)
	bool isEmpty(); // zwraca prawde jesli drzewo jest puste

};



#endif