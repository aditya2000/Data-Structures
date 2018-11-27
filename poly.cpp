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
			tail->next = newNode;
			tail = tail->next;
		}
	}

	void delete_node() {
		if(head == NULL) {
			cout<<"\n List is already empty!!";
		} else {
			node<T>* p =head;
			while(p->next->next != NULL) {
				p = p->next;
			}

			tail = p;
			node<T>* del_node = p->next;
			p->next = NULL;
			delete del_node;
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

void add_polys(List<int>poly_1, List<int>poly_2) {
	node<int>* p_1 = poly_1.head;
	node<int>* p_2 = poly_2.head;

	List<int> sum_poly;

	while(p_1!=NULL || p_2 != NULL) {
		node<int>* newNode = new node<int>;
		newNode->next = NULL;
		if(p_1 == NULL) {
			newNode->data = p_2->data;
			sum_poly.insert(newNode);
		} else if(p_2 == NULL) {
			newNode->data = p_1->data;
			sum_poly.insert(newNode);
		} else {
			newNode->data = p_1->data + p_2->data;
			sum_poly.insert(newNode);
		}

		p_1 = p_1->next;
		p_2 = p_2->next;
	}

	sum_poly.display();
}

int main() {
	int deg_1;
	cout<<"\n Enter the degree of first polynomial: ";
	cin>>deg_1;

	int deg_2;
	cout<<"\n Enter the degree of second polynomial: ";
	cin>>deg_2;

	List<int> poly_1;
	List<int> poly_2;

	cout<<"\n Polynomial 1:";
	for(int i=0; i<=deg_1; i++) {
		node<int>* newNode = new node<int>;
		newNode->next = NULL;
		int data = 0;
		cout<<"Enter the coefficient for x^"<<i<<" ";
		cin>>data;
		newNode->data = data;
		poly_1.insert(newNode);
	}

	cout<<"\n Polynomial 2:";
	for(int i=0; i<=deg_2; i++) {
		node<int>* newNode = new node<int>;
		newNode->next = NULL;
		int data = 0;
		cout<<"Enter the coefficient for x^"<<i<<" ";
		cin>>data;
		newNode->data = data;
		poly_2.insert(newNode);
	}

	poly_1.display();
	poly_2.display();

	add_polys(poly_1, poly_2);	
}	
