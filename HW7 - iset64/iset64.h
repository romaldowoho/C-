#ifndef ISET64_H
#define ISET64_H

#include "../util/util.h"
#include "BST.cpp"

class iset64 {
BST temp;
public:
	BST tree;
	iset64();
	iset64(int arr[], int size);
	iset64(int k);
	~iset64();
	iset64& operator=(const iset64& rhs);
	friend iset64 operator+(const iset64& k,const iset64& j);
	friend iset64 operator-(const iset64& k,const iset64& j);
	friend iset64 operator*(const iset64& k,const iset64& j);
	friend bool operator==(const iset64& k,const iset64& j);
	// iset64& operator++();
	// iset64 operator++(int);
	iset64& operator+=(const iset64& k);
	iset64& operator-=(const iset64& k);
	void printSet();
	void addInt(int k);
	bool find(int k);
	//BST getTree() {return tree;};
};
#endif