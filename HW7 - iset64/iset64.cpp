#include "iset64.h"

iset64::iset64() {

}

iset64::iset64(int arr[], int size) {
	for(int i = 0; i < size; i++) {
		tree.insert(arr[i]);
	}
}

iset64::iset64(int k) {
	tree.insert(k);
}

iset64::~iset64() {

}

void iset64::printSet() {
	tree.display();
}

void iset64::addInt(int k) {
	tree.insert(k % 63 - 1);
}

bool iset64::find(int k) {
	return tree.find(k);
}

iset64& iset64::operator=(const iset64& rhs) {
	if(this != &rhs) {
		this->tree = rhs.tree;
	}
	return *this;
}

iset64 operator+(const iset64& k,const iset64& j) {
	iset64 temp;
	temp.tree.addToTree(k.tree.getRoot());
	temp.tree.addToTree(j.tree.getRoot());
	return temp;
}

iset64 operator-(const iset64& k,const iset64& j) {
	iset64 temp;
	temp.tree.addToTree(k.tree.getRoot());
	temp.tree.removeFromTree(j.tree.getRoot());
	return temp;
}

iset64 operator*(const iset64& k,const iset64& j) {
	iset64 temp;
	temp.tree.intersection(k.tree.getRoot(), j.tree.getRoot());
	return temp;
}

bool operator==(const iset64& k,const iset64& j) {
	iset64 temp;
	temp.tree.intersection(k.tree.getRoot(), j.tree.getRoot());
	if(temp.tree.getSize() == k.tree.getSize() && temp.tree.getSize() == j.tree.getSize()) {
		return true;
	} else return false;
}

// iset64& operator++(int) {
// 	tree.increment(tree.getRoot());
// 	return this;
// }

// iset64 operator++(iset64 k) {
// 	iset64 temp = k;
// 	k.tree.increment(k.tree.getRoot());
// 	return temp;
// }

iset64& iset64::operator+=(const iset64& k) {
	this->tree.addToTree(k.tree.getRoot());
	return *this;
}

iset64& iset64::operator-=(const iset64& k) {
	this->tree.removeFromTree(k.tree.getRoot());
	return *this;
};



