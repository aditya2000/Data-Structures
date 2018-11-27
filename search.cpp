#include <iostream>

using namespace std;


void linear_search(int list[], int list_size, int search_ele) {
	int index = -1;
	int flag = 0;
	for(int i=0; i<list_size; i++) {
		if(list[i] == search_ele) {
			index = i;
			flag = 1;
			break;
		}
	}

	if(flag == 1) {
		cout<<"\n Linear Search:";
		cout<<"\n Element Found at index: "<<i;
	} else {
		cout<<"\n Element not found!!";
	}
}

void binary_search(int list[], int list_size, int search_ele, int first, int last) {
	int flag = 0, index = -1;
	
		int mid = (first+last)/2;
		if(search_ele == list[mid]) {
			index = mid;
			flag = 1;
			break;
		} else if(search_ele<list[mid]) {
			last = mid;
			binary_search(list, list_size, search_ele, first, last);
		} else {
			first = mid+1;
			binary_search(list, list_size, search_ele, first, last);
		}
	

	if(flag == 1) {
		cout<<"\n Binary Search:";
		cout<<"\n Element Found at index: "<<i;
	} else {
		cout<<"\n Element not found!!";
	}
}

int main() {
	int list_size;
	cout<<"\n Enter the list size: ";
	cin>>list_size;

	int list[list_size];
	cout<<"\n Enter the list elements: ";
	for(int i=0; i<list_size; i++) {
		cin>>list[i];
	}

	int search_ele;
	cout<<"\n Enter the search element: ";
	cin>>search_ele;

	int choice = 0;

	cout<<"\n Choose one:";
	cout<<"\n \t 1. Linear Search";
	cout<<"\n \t 2. Binary Search";
	cin>>choice;

	switch(choice) {
		case 1: 
			linear_search(list, list_size, search_ele);
			break;
		case 2:
			binary_search(list, list_size, search_ele, 0, list_size-1);
			break;
		default:
			cout<<"\n Invalid Choice!!";
			break;
	}

}