#include <iostream>
using namespace std;

template <class T>
struct node {
	T data;
	node* next;
};

template <class T>
class Stack {
	node<T>* top;

public:
	Stack() {
		top = NULL;
	}

	void push(node<T>* newNode) {
		if(top == NULL) {
			top = newNode;
		} else {
			node<T>* p = top;
			top = newNode;
			top->next = p;
		}
	}

	void pop() {
		if(top == NULL) {
			cout<<"\n Stack is empty!!";
		} else {
			node<T>* p = top; 
			top = top->next;
			delete p;
		}
	}

	void display() {
		node<T>* p = top;
		cout<<"\n Data(latest first): ";
		while(p != NULL) {
			cout<<p->data<<" ";
			p = p->next;
		}
	}
};


int main() {
	node<int>* newNode = new node<int>;
	newNode->data = 10;
	newNode->next = NULL;

	node<int>* newNode2 = new node<int>;
	newNode2->data = 20;
	newNode2->next = NULL;

	node<int>* newNode3 = new node<int>;
	newNode3->data = 30;
	newNode3->next = NULL;

	Stack<int> stack;
	stack.push(newNode);
	stack.push(newNode2);
	stack.push(newNode3);
	stack.pop();
	stack.display();
}