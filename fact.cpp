#include <iostream>
using namespace std;

int fact_rec(int num) {
	int fact;
	if(num == 0 || num == 1) {
		fact = 1;
	} else {
		fact = num * fact_rec(num-1);
	}
	return fact;
}

int fact_iter(int num) {
	int fact = 1;
	if(num == 0 || num == 1) {
		fact = 1;
	} else {
		int i = 1;
		while(i <= num) {
			fact *= i;
			i++;
		}
	}
	return fact;
}

int main() {
	int num = 0;
	cout<<"\n Enter the number: ";
	cin>>num;

	cout<<"\n";

	int fact_R = fact_rec(num);
	cout<<"\n Factorial(recursion): "<<fact_R;

	int fact_I = fact_iter(num);
	cout<<"\n Factorial(iteration): "<<fact_I;
}
