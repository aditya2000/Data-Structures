#include <iostream>
using namespace std;

template <class T>
struct node {
	T data;
	node* next;
	node* prev;
};

template <class T>
class List {
public:
	node<T>* head;
	node<T>* tail;

	List() {
		head = NULL;
		tail = NULL;
	}

	void insert(node<T>* newNode) {
		if(head == NULL) {
			head = tail = newNode;
		} else {
			tail->next = newNode;
			newNode->prev = tail;
			tail = tail->next;
		}
	}

	void delete_node() {
		if(head == NULL) {
			cout<<"\n List is already empty!!";
		} else {
			node<T>* p = tail;
			tail = tail->prev;
			tail->next = NULL;
			p->prev = NULL;
			delete p;
		}
	}

	void search(int data) {
		int count = 0, flag = 0;
		node<T>* p = head;
		while(p != NULL) {
			count++;
			if(p->data == data) {
				flag = 1;
				break;
			}
			p = p->next;
		}
		if(flag == 1) {
			cout<<"\n Data Found at index: "<<count;
			cout<<endl;
		} else {
			cout<<"\n Data Not Found!!";
			cout<<endl;
		}
	} 

	void display() {
		if(head ==NULL){
			cout<<"Empty List";
			cout<<endl;
		} else{
			node<T>*p = head;
			cout<<"\n Data:";
			while(p != NULL) {
				cout<<p->data<<" ";
				p = p->next;
			}
			cout<<endl;
		}
	}
};


void reverse_list(List<int> list, List<int> list_rev) {
	node<int>* p = list.tail;
	while(p != NULL) {
		node<int>* newNode = new node<int>;
		newNode->data = p->data;
		newNode->next = NULL;
		newNode->prev = NULL;
		list_rev.insert(newNode);
		p = p->prev;
	}
	list_rev.display();
}


int main() {
	node<int>* newNode = new node<int>;
	newNode->data = 10;
	newNode->next = NULL;
	newNode->prev = NULL;

	node<int>*newNode2 = new node<int>;
	newNode2->data = 20;
	newNode2->next = NULL;
	newNode2->prev = NULL;
	
	node<int>*newNode3 = new node<int>;
	newNode3->data = 30;
	newNode3->next = NULL;
	newNode3->prev = NULL;
	
	node<int>*newNode4 = new node<int>;
	newNode4->data = 40;
	newNode4->next = NULL;
	newNode4->prev = NULL;

	List<int> list;
	list.insert(newNode);
	list.insert(newNode2);
	list.insert(newNode3);
	list.insert(newNode4);
	list.search(30);
	//list.delete_node();
	list.display();

	List<int> list2;

	reverse_list(list, list2);
}