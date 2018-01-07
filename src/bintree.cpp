#include <iostream>
#include <cstdlib>
#include <string>
#include <stdio.h>
#include <algorithm>

#include "bintree.h"

//
//	KONSTRUKTOR
//

template <typename T>
MyBinTree<T>::MyBinTree(){
	size=0;
	root = new MyBinTreeNode<T>;

}

//
//	DESTRUKTOR
//

template <typename T>
MyBinTree<T>::~MyBinTree(){ }

//
//	SPRAWDZA CZY DRZEWO JEST PUSTE
//

template <typename T>
bool MyBinTree<T>::isEmpty(){
	if(size==0) return true;
	else return false;
}

//
//	ZWRACA WYSOKOSC OD PODANEGO WSKAZNIKA
//

template <typename T>
int MyBinTree<T>::getHeight(MyBinTreeNode<T>* start){
	int height = 0;
	if(start!=nullptr){
		int l_height = getHeight(start->getLeft());
		int r_height = getHeight(start->getRight());
		int max = std::max(l_height, r_height);
		height = max +1;
	}
	return height;
}

//
//	ZWRACA ROZNICE WYSOKOSCI
//

template <typename T>
int MyBinTree<T>::getDifference(MyBinTreeNode<T>* start){
	int l_height = getHeight(start->getLeft());
	int r_height = getHeight(start->getRight());
	int diff = l_height - r_height;
	return diff;
}

//
//	DODAWANIE ELEMENTU DO DRZEWA
//

template <typename T>
MyBinTreeNode<T>* MyBinTree<T>::add(MyBinTreeNode<T>* node, T elem){
	if(size == 0){
		node->setElement(elem);
		node->setLeft(nullptr);
		node->setRight(nullptr);
		++size;
		return node;
	}else if(node == nullptr){
		node = new MyBinTreeNode<T>;
		node->setElement(elem);
		node->setLeft(nullptr);
		node->setRight(nullptr);
		++size;
		return node;
	}else if(elem < node->getElement()){
		node->setLeft(add(node->getLeft(), elem));
		node = balance(node);

	}else if(elem >= node->getElement()){
		node->setRight(add(node->getRight(), elem));
		node = balance(node);

	}
	return node;
}

//
//	USUWANIE ELEMENTU DRZEWA
//

template <typename T>
void MyBinTree<T>::remove(MyBinTreeNode<T>* node, T elem){
	static MyBinTreeNode<T>* father = new MyBinTreeNode<T>;
	if(size != 0 && node!=nullptr){
		if(node->getElement()==elem){
			if(node->getLeft()!=nullptr || node->getRight()!=nullptr){
				father=node;
				remove(node->getRight(), elem);
				father=node;
				remove(node->getLeft(), elem);
				return;
			}
			else{
				if(father->getLeft()==node)
					father->setLeft(nullptr);
				if(father->getRight()==node)
					father->setRight(nullptr);
				// balance(node);
				father=node;
				--size;
				return;
			}
		}else{
			remove(node->getLeft(), elem);
			remove(node->getRight(), elem);
		}
	}else return;
}

//
//	FUNKCJA ROWNOWAZACA DRZEWO
//

template <typename T>
MyBinTreeNode<T>* MyBinTree<T>::balance(MyBinTreeNode<T>* node){
	int factor = getDifference(node);
	if(factor > 1){
		if(getDifference(node->getLeft()) > 0)
			node = llrotate(node);
		else
			node = lrrotate(node);
	}else if(factor < -1){
		if(getDifference(node->getRight()) > 0)
			node = rlrotate(node);
		else
			node = rrrotate(node);
	}
	return node;
}

//
//	ROTACJE
//

template <typename T>
MyBinTreeNode<T>* MyBinTree<T>::llrotate(MyBinTreeNode<T>* node){
	MyBinTreeNode<T>* tmp = new MyBinTreeNode<T>;
	tmp = node->getLeft();
	node->setLeft(tmp->getRight());
	tmp->setRight(node);
	return tmp;
}

template <typename T>
MyBinTreeNode<T>* MyBinTree<T>::rrrotate(MyBinTreeNode<T>* node){
	MyBinTreeNode<T>* tmp = new MyBinTreeNode<T>;
	tmp = node->getRight();
	node->setRight(tmp->getLeft());
	tmp->setLeft(node);
	return tmp;
}

template <typename T>
MyBinTreeNode<T>* MyBinTree<T>::lrrotate(MyBinTreeNode<T>* node){
	MyBinTreeNode<T>* tmp = new MyBinTreeNode<T>;
	tmp = node->getLeft();
	node->setLeft(rrrotate(tmp));
	return llrotate(node);
}

template <typename T>
MyBinTreeNode<T>* MyBinTree<T>::rlrotate(MyBinTreeNode<T>* node){
	MyBinTreeNode<T>* tmp = new MyBinTreeNode<T>;
	tmp = node->getRight();
	node->setRight(llrotate(tmp));
	return rrrotate(node);
}

//
//	FUNKCJA WYSWIETLAJACA DRZEWO
//

template <typename T>
void MyBinTree<T>::display(MyBinTreeNode<T>* start, int level){
	if(start!=nullptr){
		display(start->getRight(), level+1);
		std::cout << "\n";
		if(start == root)
			std::cout << "root-> ";
		for(int i=0; i < level && start != root; i++){
			std::cout << "\t";
		}
		std::cout << start->getElement();
		display(start->getLeft(), level+1);
	}
}


template class MyBinTree<int>;
template class MyBinTree<float>;
template class MyBinTree<double>;