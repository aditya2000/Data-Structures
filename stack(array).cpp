#include <iostream>
using namespace std;
int MAX = 100;

template <class T>
class Stack {
	T arr[10];
	T* ptr;

public:
	Stack() {
		ptr = arr;
	}
	void push(T data) {
		if(arr == NULL) {
			ptr = arr;
			*ptr = data;
		} else {
			*ptr = data;
			ptr++;
		}
	}

	void pop() {
		if(arr == NULL) {
			cout<<"\n Stack is empty!!";
		} else {
			ptr--;
		}
	}

	void display() {
		T* i;
		cout<<"\n Data: ";
		for(i=arr; i!=ptr; i++) {
			cout<<*i<<" ";
		}
	}
};

int main() {
	Stack<int> stack;

	stack.push(10);
	stack.push(20);
	stack.display();
}