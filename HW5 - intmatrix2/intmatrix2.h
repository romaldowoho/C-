#ifndef INTMATRIX2_H
#define INTMATRIX2_H

#include "../util/util.h"

class intmatrix2 {
private:
	int** _matrix;
	int _rows;
	int _cols;
	int _vals;
public:
	intmatrix2(int r = 0, int c = 0, int v = 0);
	intmatrix2(const char* string_matrix);
	intmatrix2(const intmatrix2& m);
	~intmatrix2();
	intmatrix2& operator=(const intmatrix2& rhs);
	friend std::ostream &operator<<(std::ostream &os, const intmatrix2 &m);
	void print (const char* matrix_name) const;
	bool isEqual(intmatrix2& m);
	bool isEmpty();
	intmatrix2 add(intmatrix2& m);
	intmatrix2 mult(intmatrix2& m);
};

#endif