#include <iostream>
#include <cstdlib>
#include <time.h> 

using namespace std;

void przydzielPamiec1D(int *&tab, int n);

void przydzielPamiec2D(int **&tab, int w, int k);

void wypelnijTablice1D(int *tab, int n, int a, int b);

void wypelnijTablice2D(int **tab, int w, int k, int a, int b);

void usunTablice1D(int *&tab);

void usunTablice2D(int **&tab, int w);

void wyswietl1D(int* tab, int n);

void wyswietl2D(int** tab, int w, int k);

int min1D(int* tab, int n, int b, bool* p);

void ileRazyPojawilaLiczba(int* tabMain, int* tabNew, int n);

void wyswTabIleRazowej(int* tab);



int main(){
	int n, a, b;
	bool* czyPierwsza;
	
	cout << "Rozmiar tablicy: ";
	cin >> n;
	cout << "Zakres dolny: ";
	cin >> a;
	cout << "Zakres gorny: ";
	cin >> b;
	int *tab1;
	
	przydzielPamiec1D(tab1, n);
	wypelnijTablice1D(tab1, n, a, b);
	cout << "\nTablica jednowymiarowa:\n";
	wyswietl1D(tab1, n);
	cout << "liczba minimalna: " << min1D(tab1, n, b, czyPierwsza);
	cout << "\nCzy to liczba pierwsza: " << czyPierwsza;
	usunTablice1D(tab1);
	
	
	
}

void przydzielPamiec1D(int *&tab, int n){
	tab = new int[n];
}

void wypelnijTablice1D(int *tab, int n, int a, int b){
	srand(time(NULL));
	for(int i=0; i < n; i++){
		tab[i] = rand()%(b-a) + a;
	}
}

void usunTablice1D(int *&tab){
	delete[] tab;
}

void wyswietl1D(int* tab, int n){
	for(int i=0; i<n; i++){
		cout << tab[i] << "\t";
	}
	cout << endl;
}

int min1D(int* tab, int n, int b, bool* p){
	int min = tab[0];
	for(int i=1; i < n; i++ ){
		if(min > tab[i]){
			min = tab[i];
		}
	}
	for(int i=2; i<n; i++){
		if(min%i==0){
			*p = false;
			break;
		}
	}
	return min;
	
//	for(int i=0; i < n-1; i++ ){
//		for(int j=0; j < i; j++){
//			if(tab[j] > tab[j+1]){
//				int temp = tab[j+1];
//				tab[j+1] = tab[j];
//				tab[j] = temp; 
//			}
//		}
//	}
}

void ileRazyPojawilaLiczba(int* tabMain, int* tabNew, int n){
	for(int i=0; i<n; i++){
		tabNew[tabMain[i]] ++;
	}
}

void wyswTabIleRazowej(int* tab){
	for(int i=0; i<10; i++){
		cout<< "Liczba " << i << " pojawila sie " << tab[i] << " razy\n";
	}
}


