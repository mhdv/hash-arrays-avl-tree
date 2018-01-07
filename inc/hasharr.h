#ifndef HASHARR_H
#define HASHARR_H
#include "list.h"


template <typename T>
class MyHashArr{
private:
	int arrsize;
	int secondhash;
	T* hasharr;
	MyList<T>* linkedhasharr;
	char collision_type;
	int hashFunction(T elem); //pierwsza funkcja haszujaca
	int secondHashFunction(T elem); //druga funkcja haszujaca
public:
	MyHashArr(int size, char type = 'l');
	~MyHashArr();

	bool arrayFull();

	int getSize(){return arrsize;} // zwraca arrsize
	int addElem(T elem);	// int ma zwracac ilosc probek
	int removeElem(T elem); // usuwa element

	T getElem(int k);
	int findElem(T elem);

};



#endif