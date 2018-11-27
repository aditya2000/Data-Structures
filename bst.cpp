#include <iostream>
using namespace std;

struct node {
	int data;
	node* left;
	node* right;
};

class Tree {
public:
	node* root;
	Tree() {
		root = NULL;
	}

	void insert(int val) {
		node* newNode = new node();
		newNode->data = val;
		newNode->left = NULL;
		newNode->right = NULL;
		if(root == NULL) {
			root = newNode;
		} else {
			if(newNode->data < root->data) {
				insert_left(newNode, root);
			} else {
				insert_right(newNode, root);
			}
		}
		
	}

	void insert_left(node* newNode, node* trav) {
		if(trav->left == NULL) {
			trav->left = newNode;
		} else {
			trav = trav->left;
			if(newNode->data < trav->data) {
				insert_left(newNode, trav);
			} else {
				insert_right(newNode, trav);
			}
		}
	} 

	void insert_right(node* newNode, node* trav) {
		if(trav->right == NULL) {
			trav->right = newNode;
		} else {
			trav = trav->right;
			if(newNode->data < trav->data) {
				insert_left(newNode, trav);
			} else {
				insert_right(newNode, trav);
			}
		}
	}

	void display_inorder(node* trav) {
		if(trav != NULL) {
			display_inorder(trav->left);
			cout<<"\n"<<trav->data<<" "<<endl;
			display_inorder(trav->right);
		}
	} 

	void display_postorder(node* trav) {
		if(trav != NULL) {
			cout<<"\n"<<trav->data<<" "<<endl;
			display_postorder(trav->left);
			display_postorder(trav->right);
		}
	}

	void display_preorder(node* trav) {
		if(trav != NULL) {
			display_preorder(trav->left);
			display_preorder(trav->right);
			cout<<"\n"<<trav->data<<" "<<endl;
		}
	}

	node* delete_node(int data, node* trav) {
		if(trav == NULL) {
			return trav;
		}

		if(data < trav->data) {
			trav = delete_node(data, trav->left);
		} else if(data > trav->data) {
			trav = delete_node(data, trav->right);
		} else {
			if(trav->left == NULL) {
				node* temp = trav->right;
				delete trav;
				return temp;
			} else if (trav->right == NULL) {
				node* temp = trav->left;
				delete trav;
				return temp;
			}

			node* temp = minValNode(root->right);
			trav->data = temp->data;
			trav->right = delete_node(temp->data, trav->right);
		}
	}

	node* minValNode(node* nod) {
		node* current = nod;
		while(current->left != NULL) {
			current = current->left;
		}

		return current;
	}
};


int main() {
	Tree tree;

	tree.insert(10);
	tree.insert(11);
	tree.insert(1);
	tree.insert(30);
	tree.insert(5);

	//tree.delete_node(10, tree.root);
	cout<<"\n Root: "<<tree.root->data;
	cout<<"\nTree after insertion(inorder): ";
	tree.display_inorder(tree.root);
	cout<<"\nTree after insertion(postorder): ";
	tree.display_postorder(tree.root);
	cout<<"\nTree after insertion(preorder): ";
	tree.display_preorder(tree.root);
}