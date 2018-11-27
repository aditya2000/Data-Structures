#include <iostream>
using namespace std;

int gcd_rec(int num_1, int num_2) {
	if(num_2!=0) {
		return gcd_rec(num_2, num_1%num_2);
	} else {
		return num_1;
	}
}

int gcd_iter(int num_1, int num_2) {
	int gcd = 1;
	for(int i=1; i<num_1 && i<num_2; i++) {
		if(num_1%i==0 && num_2%i==0) {
			gcd = i;
		}
	}

	return gcd;
}

int main() {
	int num_1, num_2;
	cout<<"\n Enter the first number: ";
	cin>>num_1;

	cout<<"\n Enter the second number: ";
	cin>>num_2;

	cout<<"\n GCD of two numbers is(recursion): "<<gcd_rec(num_1, num_2)<<endl;
	cout<<"\n GCD of two numbers is(iteration): "<<gcd_iter(num_1, num_2)<<endl;
}