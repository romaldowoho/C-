#include "../util/util.h"
class BST {
	
	struct node {
		int data;
		node* left;
		node* right;  
	};

	node* root;

	node* insert(int x, node* t) {
		if(t == NULL) 
		{
			t = new node;
			if(x < 64) {
				t->data = x;
			} else {
				t->data = ((x % 63) - 1); 
			}
			
			t->left = t->right = NULL;
		}
		else if(x < t->data) 
		{
			t->left = insert(x,t->left);
		} 
		else if(x > t->data)
		{
			t->right = insert(x,t->right);
		}
		return t;
	}

	node* remove(int x, node* t) {
		node* temp;
		if(t == NULL) return NULL;
		else if(x < t->data) {
			t->left = remove(x,t->left);
		}
		else if(x > t->data) {
			t->right = remove(x,t->right);
		}
		else if(t->left && t->right){
			temp = findMin(t->right);
			t->data = temp->data;
			t->right = remove(t->data,t->right);
		}
		else {
			temp = t;
			if(t->left == NULL){
				t = t->right;
			}
			else if(t->right == NULL){
				t = t->left;
			}
			delete temp;
		}
		return t;
	}

	node* makeEmpty(node* t) {
		if(t == NULL) return NULL;

		makeEmpty(t->left);
		makeEmpty(t->right);
		delete t;
		return NULL;
	}

	node* findMin(node* t) {
		if(t == NULL)
		{
			return NULL;
		}
		else if(!t->left)
		{
			return t;
		}
		else return findMin(t->left);
	}

	node* findMax(node* t) {
		if(t == NULL)
		{
			return NULL;
		}
		else if(!t->right)
		{
			return t;
		}
		else return findMax(t->right);
	}

	void inorderPrint(node* t) {
		if(t == NULL) return;
		inorderPrint(t->left);
		cout << t->data << " ";
		inorderPrint(t->right);
	}

	void treeSize(node* t, int& n) const{
		if(t == NULL) return;
		treeSize(t->left, n);
		treeSize(t->right, n);
		n++;
	}

	void copyNode(node* n) {
		if(n != nullptr) {
			this->insert(n->data);
			copyNode(n->left);
			copyNode(n->right);
		}
	}

	bool findNode(node* t, int x) {
		if(t == NULL)
            return false;
        else if(x < t->data)
            return findNode(t->left, x);
        else if(x > t->data)
            return findNode(t->right, x);
        else
            return true;
	}
public:
	BST() {
		root = NULL;
	}

	~BST() {
		root = makeEmpty(root);
	}

	BST& operator=(const BST& rhs) {
		if(this != &rhs) {
			this->root = makeEmpty(this->root);
			node* temp = rhs.root;
			copyNode(temp);
		}
		return *this;
	}

	void insert(int x) {
		root = insert(x,root);
	}

	void remove(int x) {
		root = remove(x,root);
	}

	void display() {
		inorderPrint(root);
		cout << endl;
	}

	int getSize() const {
		int count = 0;
		treeSize(root,count);
		return count;
	}

	void increment(node* t) {
		if(t == NULL) return;
		increment(t->left);
		if(t->data < 63) {
			++t->data;
		} else {
			t->data = 0;
		}
		increment(t->right);
	}

	void addToTree(node* b) { //stopped here - change parameters
		if(b == NULL) return;
		addToTree(b->left);
		this->insert(b->data);
		addToTree(b->right);
	}

	void removeFromTree(node* b) {
		if(b == NULL) return;
		removeFromTree(b->left);
		this->remove(b->data);
		removeFromTree(b->right);
	}

	node* getRoot() const {
		return root;
	}

	bool find(int x) {
		return findNode(root,x);
	}

	void intersection(node* a, node* b) {
		if(a == NULL) return;
		intersection(a->left, b);
		if(findNode(b, a->data)) {
			this->insert(a->data);
		}
		intersection(a->right, b);
	}

};