#include <iostream>
using namespace std;

int main() {
	int arr[5];
	cout<<"Enter the array elements: ";
	for(int i=0; i<5; i++) {
		cin>>arr[i];
	}

	int mat_low[25];
	for(int i=0; i<5; i++) {
		for(int j=0; j<5; j++) {
			if(i<j) {
				mat_low[j] = 0;
			} else {
				mat_low[j] = arr[j];			}
		}
	}


	cout<<"\n Lower Triangle Matrix:\n";
	for(int i=0; i<5; i++) {
		for(int j=0; j<5; j++) {
			cout<<mat_low[j]<<" ";
		}
		cout<<endl;
	}

	int mat_up[5][5];
	for(int i=0; i<5; i++) {
		for(int j=0; j<5; j++) {
			if(i<=j) {
				mat_up[i][j] = arr[j];
			} else {
				mat_up[i][j] = 0;
			}
		}
	}


	cout<<"\n Upper Triangle Matrix:\n";
	for(int i=0; i<5; i++) {
		for(int j=0; j<5; j++) {
			cout<<mat_up[i][j]<<" ";
		}
		cout<<endl;
	}

	int mat_dia[5][5];
	for(int i=0; i<5; i++) {
		for(int j=0; j<5; j++) {
			if(i==j) {
				mat_dia[i][j] = arr[j];
			} else {
				mat_dia[i][j] = 0;
			}
		}
	}


	cout<<"\n Diagonal Matrix:\n";
	for(int i=0; i<5; i++) {
		for(int j=0; j<5; j++) {
			cout<<mat_dia[i][j]<<" ";
		}
		cout<<endl;
	}
}