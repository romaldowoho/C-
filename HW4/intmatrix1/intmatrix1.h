#ifndef INTMATRIX1_H
#define INTMATRIX1_H

#include "../util/util.h"

class intmatrix1 {
private:
	int** matrix;
	int* _rows;
	int* _cols;
	int _vals;
public:
	intmatrix1(int r = 0, int c = 0, int v = 0) :
	_rows{r}, _cols{c}, _vals{v};
	intmatrix1(const char* string_matrix);
	void print (const char* matrix_name) const;
	void fini();
	bool isEqual(intmatrix1 matrix2);
	bool isEmpty();
	intmatrix1 add(intmatrix1& m);
	intmatrix1 mult(intmatrix1& m);
};


#endif