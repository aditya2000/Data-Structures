#include <iostream>
using namespace std;

template <class T>
struct node {
	T data;
	node* next;
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
			newNode->next = head;
			tail->next = newNode;
			tail = newNode;
		}
	}

	void delete_node() {
		if(head == NULL) {
			cout<<"\n List is already empty!!";
		} else {
			node<T>* p =head;
			while(p->next->next != tail) {
				p = p->next;
			}

			tail = p;
			node<T>* del_node = p->next;
			p->next = NULL;
			tail->next = head;
			delete del_node;
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
		if(head == NULL){
			cout<<"Empty List";
			cout<<endl;
		} else{
			node<T>*p = head;
			cout<<"\n Data:";
			while(p != tail) {
				cout<<p->data<<" ";
				p = p->next;
			}
			cout<<endl;
			cout<<"Tail->next: "<<tail->next->data;
		}
	}
};


void reverse_list(List<int> list, List<int> list_rev) {
	int size = 0;
	node<int>* n = list.head;
	while(n != list.tail) {
		size++;
		n = n->next;
	}	

	int data_arr[size];
	n = list.head;
	int j = 0;
	while(n != list.tail) {
		data_arr[j] = n->data;
		j++;
		n = n->next;
	}

	for(int i=size-1; i>=0; i--) {
		node<int>* newNode = new node<int>;
		newNode->data = data_arr[i];
		newNode->next = NULL;
		cout<<data_arr[i]<<" ";
		list_rev.insert(newNode);
	}

	list_rev.display();
}

int main() {
	node<int>* newNode = new node<int>;
	newNode->data = 10;
	newNode->next = NULL;

	node<int>*newNode2 = new node<int>;
	newNode2->data = 20;
	newNode2->next = NULL;
	
	node<int>*newNode3 = new node<int>;
	newNode3->data = 30;
	newNode3->next = NULL;
	
	node<int>*newNode4 = new node<int>;
	newNode4->data = 40;
	newNode4->next = NULL;

	List<int> list;
	list.insert(newNode);
	list.insert(newNode2);
	list.insert(newNode3);
	list.insert(newNode4);
	list.search(30);
	//list.delete_node();
	list.display();

	List<int> list2;
	List<int> list3;

	list3.insert(newNode);
	list3.insert(newNode2);
	list3.insert(newNode3);
	list3.insert(newNode4);	

	reverse_list(list, list2);
}