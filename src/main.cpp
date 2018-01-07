#include <iostream>
#include <string>
#include <cstdlib>
#include <stdio.h>
#include <time.h>

// naglowki implementacji
#include "bintree.h"
#include "hasharr.h"

// funkcja generujaca losowe liczby bez powtorzen
void hashRandom(MyHashArr<int> arr);

int main(){


// KONFIGURACJA TABLIC HASZUJACYCH
// ##############################################################################################################################
	bool show_hash = true;					// decyduje czy program ma testowac tablice haszujace
	//######################
	//######################
	char collision = 'l';					// decyduje o typie kolizji l-linkowanie p-probkowanie liniowe d-podwojne haszowanie
	int array_size = 7;						// decyduje o wielkosci tablicy (musi byc liczba pierwsza)
	bool test_mode = false;					// test-mode jest trybem w ktorym uzytkownik decyduje o wstawianych elementach
// ##############################################################################################################################


// KONFIGURACJA DRZEWA AVL
// ##############################################################################################################################
	bool show_avl = false;					// decyduje czy program ma testowac drzewa avl
	//######################
// ##############################################################################################################################
	

	if(show_hash){
		MyHashArr<int> hasharray(array_size, collision);
		if(!test_mode){
			hashRandom(hasharray);
			for(int i=0; i<hasharray.getSize(); i++)
				if(collision=='l'){
					hasharray.getElem(i);
					std::cout << "\n";
				}else
					std::cout << hasharray.getElem(i) << "\n";
		}
		else if(test_mode){
			int option;
			do{
				system("clear");
				for(int i=0; i<hasharray.getSize(); i++)
				if(collision=='l'){
					hasharray.getElem(i);
					std::cout << "\n";
				}else
					std::cout << hasharray.getElem(i) << "\n";
				std::cout <<"\n1)Dodaj element"
							"\n2)Usun element"
							"\n3)Znajdz element"
							"\n0)Wyjdz\n";
				while(!(std::cin >> option) || option > 3 || option < 0) { std::cin.clear(); std::cin.ignore(); std::cout << "\nBledny znak..\n";}
				switch(option){
					case 1:
					{
						system("clear");
						std::cout << "Podaj liczbe do wpisania: ";
						int input;
						while(!(std::cin >> input)) { std::cin.clear(); std::cin.ignore(); std::cout << "\nBledny znak..\n";}
						
						std::cout << "\nIlosc probek: " << hasharray.addElem(input);
						getchar(); getchar();
						break;	
					}
					case 2:
					{
						system("clear");
						std::cout << "Podaj liczbe do usuniecia: ";
						int input;
						while(!(std::cin >> input)) { std::cin.clear(); std::cin.ignore(); std::cout << "\nBledny znak..\n";}
						int tmp = hasharray.findElem(input);
						if(tmp < 0) std::cout << "\nNie znaleziono takiego elementu.\n";
						else{
							hasharray.removeElem(input);
							std::cout << "\nPomyslnie usunieto element.\n";
						}
						getchar();getchar();
						break;	
					}
					case 3:
					{
						system("clear");
						std::cout << "Podaj liczbe do znalezienia: ";
						int input;
						while(!(std::cin >> input)) { std::cin.clear(); std::cin.ignore(); std::cout << "\nBledny znak..\n";}
						int tmp = hasharray.findElem(input);
						if(tmp < 0) std::cout << "\nNie znaleziono takiego elementu.\n";
						else std::cout << "\nZnaleziono szukany element pod indeksem w tab[" << tmp << "]\n";
						getchar();getchar();
						break;	
					}
					default:
					break;

				}
			}while(option!=0);
		}
	}

	if(show_avl){
		MyBinTree<int>* tree = new MyBinTree<int>;
		int option;
		do{
			system("clear");
			tree->display(tree->getRoot(), 1);
			std::cout <<"\n\n";
			std::cout <<"\n1)Dodaj element"
						"\n2)Usun element"
						"\n3)Wyswietl wysokosc"
						"\n0)Wyjdz\n";
			while(!(std::cin >> option) || option > 3 || option < 0) { std::cin.clear(); std::cin.ignore(); std::cout << "\nBledny znak..\n";}
			switch(option){
				case 1:
				{
					std::cout << "Podaj liczbe do wpisania: ";
					int input;
					while(!(std::cin >> input)) { std::cin.clear(); std::cin.ignore(); std::cout << "\nBledny znak..\n";}
					tree->add(tree->getRoot(), input);
					getchar(); getchar();
					break;	
				}
				case 2:
				{
					std::cout << "Podaj liczbe do usuniecia: ";
					int input;
					while(!(std::cin >> input)) { std::cin.clear(); std::cin.ignore(); std::cout << "\nBledny znak..\n";}
					tree->remove(tree->getRoot(), input);
					getchar();getchar();
					break;	
				}
				case 3:
				{
					std::cout << "Wysokosc drzewa to: " << tree->getHeight(tree->getRoot());
					getchar();getchar();
					break;	
				}
				default:
				break;

			}
		}while(option!=0);
		// tree->add(tree->getRoot(), 5);
		// tree->add(tree->getRoot(), 2);
		// tree->add(tree->getRoot(), 6);
		// tree->add(tree->getRoot(), 5);
		// tree->add(tree->getRoot(), 1);
		// tree->add(tree->getRoot(), 6);
		// tree->add(tree->getRoot(), 2);
		// tree->add(tree->getRoot(), 6);
		// tree->add(tree->getRoot(), 5);
		// tree->add(tree->getRoot(), 1);
		// tree->add(tree->getRoot(), 6);
		// tree->remove(tree->getRoot(), 5);
		// tree->remove(tree->getRoot(), 6);
		// tree->remove(tree->getRoot(), 5);
		// tree->remove(tree->getRoot(), 6);
		// tree->remove(tree->getRoot(), 5);
		// tree->remove(tree->getRoot(), 6);
		// tree->display(tree->getRoot(), 1);
		// std::cout << "\n\n\n";
	}

// // test drzewa binarnego
// 	MyBinTree<int>* drzewobin = new MyBinTree<int>;
// 	drzewobin->add(1,0);
// 	drzewobin->add(2,1);
// 	drzewobin->add(4,2);
// 	drzewobin->add(3,1);
// 	drzewobin->add(5,3);
// 	drzewobin->add(6,1);
// 	drzewobin->add(7,3);
// 	drzewobin->add(8,7);
// 	drzewobin->remove(5);
// 	drzewobin->remove(8);
// 	drzewobin->add(100, 3);
// 	drzewobin->remove(1);

// 	drzewobin->add(1,1);
// 	drzewobin->add(2,1);
// 	drzewobin->add(3,2);
// 	drzewobin->add(4,3);
// 	std::cout << drzewobin->getHeight(drzewobin->getRoot()) << "\n";

	return 0;
}




void hashRandom(MyHashArr<int> arr){
	srand(time(NULL));
	int* tmparr = new int[arr.getSize()];
	for(int i=0; i<arr.getSize(); i++){
		bool duplicate = false;
		tmparr[i]=rand()%(arr.getSize()*10)+1;
		for(int j=0; j<i; j++){
			if(tmparr[i]==tmparr[j]) duplicate = true;
		}
		if(duplicate) --i;
	}
	for(int i=0; i<arr.getSize(); i++){
		arr.addElem(tmparr[i]);
	}
}
