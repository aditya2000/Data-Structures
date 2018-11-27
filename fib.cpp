#include <iostream>
using namespace std;

int fib_rec(int num) {
	int fib_1, fib_2;
	if(num <=1) {
		return num;
	}
	return fib_rec(num-1)+fib_rec(num-2);
}

int fib_iter(int num) {
	if(num == 0) {
		return 0;
	}

	if(num == 1) {
		return 1;
	}

	int fib; 
	int first=0, sec=1;
	for(int i=2; i<=num; i++) {
		fib = first+sec;
		first = sec;
		sec = fib;
	}

	return fib;
}

int main() {
	int num = 0;
	cout<<"\n Enter the number: ";
	cin>>num;

	cout<<"\n";


	cout<<"\n Fibonacci(recursion): ";
	for(int i=0; i<num; i++) {
		cout<<fib_rec(i)<<" ";
	}

	cout<<"\n Fibonacci(iteration): ";
	for(int i=0; i<num; i++) {
		cout<<fib_iter(i)<<" ";
	}
}
