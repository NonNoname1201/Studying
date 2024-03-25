#include <iostream>
#include <cmath>

using namespace std;

void discrimSolution(double a, double b, double c, double &x1, double &x2);
void vietSolution(double a, double b, double c, double &x1, double &x2);
double sign(double a);

int main(){
	double a = 0, b = 0, c = 0;
	double x1, x2;
	while(true){
		cout<< "Podaj liczbe \"a\": ";
		cin>> a;
		cout<< "Podaj liczbe \"b\": ";
		cin>> b;
		cout<< "Podaj liczbe \"c\": ";
		cin>> c;
		
		double delta = b*b - (4*a*c);
		if(delta >=0 ){
			discrimSolution (a, b, c, x1, x2);
			vietSolution (a, b, c, x1, x2);
		}
		else{
			cout << "Delta < 0!!!" << endl;
		}
		
		
	}
	
	
	return 0;
}


void discrimSolution(double a, double b, double c, double &x1, double &x2){
	double delta = b*b - (4*a*c);
	x1 = (-b - sqrt(delta))/(2*a);
	x2 = (-b + sqrt(delta))/(2*a);
		
	cout << "Odpowiedz przez klasyczne metode: "<< x1 << "  " << x2 << endl << endl;
}

void vietSolution(double a, double b, double c, double &x1, double &x2){
	double temp = b/(2*a);
	x1 = -temp + sign(-temp)*sqrt(temp*temp - (c/a));
	x2 = c/(a*x1);
		
	cout << "Odpowiedz przez alternatywna metode: "<< x1 << "  " << x2 << endl << endl;	
}

double sign(double a){
	if(a>0){
		return 1;
	}
	else if(a<0){
		return -1;
	}
	return 0;
}
