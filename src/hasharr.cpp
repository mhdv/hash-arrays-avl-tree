#include "hasharr.h"
#include "othermethods.h"

//
//	KONSTRUKTOR
//

template <typename T>
MyHashArr<T>::MyHashArr(int size, char type){
	if(!isPrime(size)){
		std::cerr << "\nLiczba nie jest pierwsza. Przyjmuje domyslnie 7.\n";
		size=7;
	}
	if(type!='l' && type!='p' && type!='d'){
		std::cerr << "\nBledny typ kolizji. Przyjmuje domyslnie linkowanie.\n";
		type = 'l';
	}
	collision_type = type;
	arrsize = size;
	secondhash = lowerPrime(arrsize);
	hasharr = new T[arrsize];
	linkedhasharr = new MyList<T>[arrsize];
}

//
//	DESTRUKTOR
//

template <typename T>
MyHashArr<T>::~MyHashArr(){ }

//
//	SPRAWDZA CZY TABLICA JEST PELNA
//

template <typename T>
bool MyHashArr<T>::arrayFull(){
	for(int i=0; i<arrsize; i++){
		if(hasharr[i]==0) return false;
	}
	return true;
}

//
//	PIERWSZA FUNKCJA HASZUJACA
//

template <typename T>
int MyHashArr<T>::hashFunction(T elem){
	return elem%arrsize;
}

//
//	DRUGA FUNKCJA HASZUJACA
//

template <typename T>
int MyHashArr<T>::secondHashFunction(T elem){
	return (secondhash-(elem%secondhash));
}

//
//	DODANIE ELEMENTU ZALEZNIE OD KOLIZJI
//

template <typename T>
int MyHashArr<T>::addElem(T elem){
	int hash = hashFunction(elem);
	int tmp = hash;
	int sample = 0;
	switch(collision_type){
		case 'l':
		{
			if(!linkedhasharr[hash].findElement(elem))
				linkedhasharr[hash].addFront(elem);
			else
				std::cerr << "\nTaki element juz istnieje!\n";
			sample++;
			break;
		}
		case 'p':
		{
			bool added = false;
			if(hasharr[hash]==0){ hasharr[hash] = elem; sample++;}
			else{
				for(int i=tmp; i<arrsize; i++){
					sample++;
					if(hasharr[i]==elem){
						std::cerr << "\nTaki element juz istnieje!\n";
						added = true;
						break;
					}
					if(hasharr[i]==0){
						hasharr[i] = elem;
						added = true;
						break;
					}
				}
				if(!added)
					for(int i=0; i<hash; i++){
						sample++;
						if(hasharr[i]==elem){
							std::cerr << "\nTaki element juz istnieje!\n";
							added = true;
							break;
						}
						if(hasharr[i]==0){
							hasharr[i] = elem;
							added = true;
							break;
						}
					}
				if(!added) std::cerr << "\nTablica jest pelna!\n";
			}
			break;
		}
		case 'd':
		{
			bool added = false;
			int hash2 = secondHashFunction(elem);
			int tmp2 = hash2;

			while(!added){	// petla wykona sie do konca w najgorszym mozliwym przypadku
				sample++;
				if(hasharr[tmp]==0){
					hasharr[tmp] = elem;
					added = true;
					break;
				}
				if(hasharr[tmp]==elem){
					std::cerr << "\nTaki element juz istnieje!\n";
					added = true;
					break;
				}
				if(arrayFull()){
					std::cerr << "\nTablica jest juz pelna!\n";
					added = true;
					break;
				}
				tmp = tmp+tmp2;
				tmp = tmp%arrsize;
			}
			break;
		}
		default:
		std::cerr << "\nChyba cos poszlo nie tak..\n";
		break;
	}
	return sample;
}

//
//	ZNAJDOWANIE ELEMENTU ZALEZNIE OD KOLIZJI
//

template <typename T>
int MyHashArr<T>::findElem(T elem){
	int hash = hashFunction(elem);
	int tmp = hash;
	bool found = false;
	switch(collision_type){
		case 'l':
		{
			if(elem == 0){
				std::cout << "\nNie mozna wyszukac zera.\n";
				return -1;
			}
			if(linkedhasharr[hash].findElement(elem)) return hash;
			else return -1;
			break;
		}
		case 'p':
		{
			if(elem == 0){
				std::cout << "\nNie mozna wyszukac zera.\n";
				return -1;
			}
			for(int i=tmp; i<arrsize; i++){
				if(hasharr[i]==elem){
					found = true;
					return i;
					break;
				}
				if(hasharr[i]==0){
					found = true;
					std::cout << "\nNie ma takiego elementu!\n";
					return -1;
					break;
				}
			}
			if(!found)
				for(int i=0; i<hash; i++){
					if(hasharr[i]==elem){
						found = true;
						return i;
						break;
					}
					if(hasharr[i]==0){
						found = true;
						std::cout << "\nNie ma takiego elementu!\n";
						return -1;
						break;
					}
				}
			if(!found) std::cerr << "\nNie ma takiego elementu.\n";
			return -1;
			break;
		}
		case 'd':
		{
			int hash2 = secondHashFunction(elem);
			int tmp2 = hash2;
			int counter = 0;
			while(!found){	// petla wykona sie do konca w najgorszym mozliwym przypadku
				if(hasharr[tmp]==0){
					std::cerr << "\nNie ma takiego elementu.\n";
					found = true;
					return -1;
					break;
				}
				if(hasharr[tmp]==elem){
					found = true;
					return tmp;
					break;
				}
				tmp = tmp+tmp2;
				tmp = tmp%arrsize;
				counter++;
				if(counter>arrsize){
					std::cerr << "\nNie ma takiego elementu.\n";
					found = true;
					return -1;
					break;
				}
			}
			break;
		}
	}
	return 0;
}

//
//	USUWANIE ELEMENTU
//

template <typename T>
int MyHashArr<T>::removeElem(T elem){
	if(collision_type!='l'){
		int tmp = findElem(elem);
		if(tmp <0) return -1;
		if(tmp >=0) hasharr[tmp]=0;
		return tmp;
	}else{
		linkedhasharr[findElem(elem)].removeFront();
		return 1;
	}
}

//
//	ZWRACA ELEMENT/WYSWIETLA W PRZYPADKU LINKOWANIA
//

template <typename T>
T MyHashArr<T>::getElem(int k){
	if(collision_type=='l'){
		if(!linkedhasharr[k].empty()){
			linkedhasharr[k].displayList();	
			 return 0;
		}
		else{
			std::cout << "0";
			return 0;
		}
	}
	return hasharr[k];
}

template class MyHashArr<int>;