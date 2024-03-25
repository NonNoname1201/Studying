#include <iostream>

using namespace std;

long decToBin(int num){
	long binNum = 0;
	long order = 1;
	while(num != 0){
		binNum += (num % 2) * order;
		num /= 2;
		order *=10;
	}
	return binNum;
}

int main(){
	int num = 0;
	cout<<"-1 Dla wyjscia\n";
	while(num >= 0){
		cout<< "Podaj liczbe w podstawie Dziesietnej: ";
		cin>> num;
		cout << "Your number in Binary: " << decToBin(num) << endl << endl;
	}
	
	
	return 0;
}
