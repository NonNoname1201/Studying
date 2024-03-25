#include <iostream>
#include <cmath>
using namespace std;

void horner(double* A);

int main(){
	double* A;
	horner(A);
	return 0;
}

void horner(double* A){
	int size = 0;
	
	cout << "Podaj stopien wielomianu: ";
	cin >> size;
	size++;
	
	//-----------------------
	
	A = new double(size);
	for(int i=0; i<size; i++){
		cout << "Podaj liczbe dla stopieniu " << size - i - 1 << ": ";
		cin >> A[i];
	}
	
	//-----------------------
	
	double point = 0;
	cout << "Podaj punkt rozwiazywania: ";
	cin >> point;
	
	//-----------------------
	
	double answer = 0;
	for(int i = 0; i < size; i++){
		answer = answer * point + A[i];
	}
	
	cout << "Odpowiedz w punlcie " << point
		 << " stanowi: " << answer; 
	
}


