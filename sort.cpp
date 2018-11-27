#include <iostream>
using namespace std;

void selection_sort(int list[], int list_size) {
	for(int i=0; i<list_size; i++) {
		for(int j=i; j<list_size; j++) {
			int temp = 0;
			if(list[i] > list[j]) {
				temp = list[i];
				list[i] = list[j];
				list[j] = temp;
			}
		}
	}

	cout<<"\n Sorted List(Selection): ";
	for(int i=0; i<list_size; i++) {
		cout<<list[i]<<" ";
	}
	cout<<endl;
}

void bubble_sort(int list[], int list_size) {
	for(int i=0; i<list_size; i++) {
		for(int j=0; j<list_size-i-1;j++) {
			int temp = 0;
			if(list[j] > list[j+1]) {
				temp = list[j];
				list[j] = list[j+1];
				list[j+1] = temp;
			}
		}
	}

	cout<<"\n Sorted List(Bubble): ";
	for(int i=0; i<list_size; i++) {
		cout<<list[i]<<" ";
	}
	cout<<endl;
}

void insertion_sort(int list[], int list_size) {
	int key, j;
	for(int i=1; i<list_size; i++) {
		key = list[i];
		j = i-1;
		while(j>=0 && list[j]>key) {
			list[j+1] = list[j];
			j = j-1;
		}

		list[j+1] = key;
	}

	cout<<"\n Sorted List(Insertion): ";
	for(int i=0; i<list_size; i++) {
		cout<<list[i]<<" ";
	}
	cout<<endl;
}

int main() {
	int list_size;
	cout<<"\n Enter the size of the list: ";
	cin>>list_size;

	int list[list_size];
	cout<<"\n Enter the list elements: ";
	for(int i=0; i<list_size; i++) {
		cin>>list[i];
	}

	int choice;

	cout<<"\n Enter the choice: ";
	cout<<"\n \t 1.Selection ";
	cout<<"\n \t 2.Bubble ";
	cout<<"\n \t 3.Insertion\n";
	cin>>choice;

	switch(choice) {
		case 1: 
			selection_sort(list, list_size);
			break;
		case 2: 
			bubble_sort(list, list_size);
			break;
		case 3: 
			insertion_sort(list, list_size);
			break;
	}
}