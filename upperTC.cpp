#include <iostream>
using namespace std;

int main() {
	int data[15];
	cout << "Enter Values:";
					for (int i = 1; i <= 5; i++) {
						int value;
						for (int j = 1; j <= 5 ; j++) {
							cin >> value;
							if(i <= j) {
								int k = ((j * (j - 1)) / 2)	+ (i -1) ;
								data[k] = value;
							} else {
								data[j] = 0;
							}
						}
					}

	cout<<"\n Data: ";
	for(int i=1; i<=5; i++) {
		for(int j=1; j<=5; j++) {
			cout<<data[j]<<" ";
		}
		cout<<endl;
	}
}