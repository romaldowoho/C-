#include "intmatrix1.h"

	intmatrix1::intmatrix1(int r = 0, int c = 0, int v = 0) {
			if (r == 0 || c == 0) {
				_matrix = nullptr;
				return;
			}
				
			_matrix = new int*[r];
			for (int i = 0; i < r; i++) {
				_matrix[i] = new int[c];
			}

			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
						_matrix[i][j] = v;
				}
			}
	}

	intmatrix1::intmatrix1(const char* string_matrix) {
		int size = strlen(string_matrix);
		int bar_count = 0;
		vector<int> vec;

		for (int i = 0; i < size; i++) {
			if (string_matrix[i] == '|')  {
				bar_count++;
				continue;
			}
			if (string_matrix[i] != ' ' && string_matrix[i] != '|') {
				if(string_matrix[i+1] == ' ' || string_matrix[i+1] == '|') {
					vec.push_back(string_matrix[i] - '0');
				} else {
					int j = i;
					int temp_num = 0;
					int counter = 0;

					while((string_matrix[j] != ' ' && string_matrix[j] != '|') && string_matrix[j] != '\0') {
						int temp_digit = string_matrix[j] - '0';
						temp_num = temp_num * 10 + temp_digit;
						j++;
						counter++;
					}
					vec.push_back(temp_num);
					i += counter - 1;
				}
				
			}
		}
		_cols = vec.size() / (bar_count + 1);
		_rows = bar_count + 1;
		if (vec.size() % (bar_count + 1) != 0) {
			_rows = _cols = _vals = 0;
			_matrix = nullptr;
			return;
		}
		_matrix = new int*[_rows];
		for (int i = 0; i < _rows; i++) {
				_matrix[i] = new int[_cols];
			}
		int vec_index = 0;
		for (int i = 0; i < _rows; i++) {
				for (int j = 0; j < _cols; j++) {
						_matrix[i][j] = vec[vec_index];
						vec_index++;
				}
			}
	}


	void intmatrix1::print (const char* matrix_name) const {
		cout << "------- " << matrix_name << " -------" << endl;
		if (_matrix) {
			for (int i = 0; i < _rows; i++) {
				for (int j = 0; j < _cols; j++) {
					cout << _matrix[i][j] << " ";
				}
				cout << endl;
			}
		} else {
			cout << "Empty matrix" << endl;
			return;
		}
	}

	void intmatrix1::fini() {
		for (int i = 0; i < _rows; i++) {
			for (int j = 0; j < _cols; j++) {
				_matrix[i][j] = 0;
			}
		}
		delete[] _matrix;
		_matrix = nullptr;

	}

	bool intmatrix1::isEqual(intmatrix1& matrix2) {
		if((_rows != matrix2._rows || _cols != matrix2._cols) || _vals != matrix2._vals) {
			return 0;
		} else {
			for (int i = 0; i < _rows; i++) {
				for (int j = 0; j < _cols; j++) {
					if (_matrix[i][j] != matrix2._matrix[i][j]) {
						return 0;
					}
				}		
			}
		}
		return 1;
	}

	bool intmatrix1::isEmpty() {
		if((_rows == 0 || _cols == 0) || _vals == 0) {
			return 1;
		} else return 0;
	}

	intmatrix1 intmatrix1::add(intmatrix1& m) {
		if(this->_rows == m._rows && this->_cols == m._cols) {
			intmatrix1 temp(m._rows,m._cols, 0);
			for (int i = 0; i < _rows; i++) {
				for (int j = 0; j < _cols; j++) {
						temp._matrix[i][j] = this->_matrix[i][j] + m._matrix[i][j];
				}
			}
			return temp;
		} else {
			intmatrix1 temp(0,0,0);
			return temp;
		}
	}

	intmatrix1 intmatrix1::mult(intmatrix1& m) {
		//if left side is scalar
		if(this->_cols == 1 && this->_rows == 1) {
			intmatrix1 temp(m._rows,m._cols,0);
			int mult = this->_matrix[0][0];
			for(int i = 0; i < m._rows; i++) {
				for(int j = 0; j < m._cols; j++) {
					temp._matrix[i][j] = mult * m._matrix[i][j];
				}
			}
			return temp;
		} //if right side is scalar
		else if(m._cols == 1 && m._rows == 1) {
			intmatrix1 temp(this->_rows,this->_cols,0);
			int mult = m._matrix[0][0];
			for(int i = 0; i < this->_rows; i++) {
				for(int j = 0; j < this->_cols; j++) {
					temp._matrix[i][j] = mult * this->_matrix[i][j];
				}
			}
			return temp;
		} else if(this->_cols == m._rows) {
			int rows = this->_rows;
			int cols = m._cols;
			intmatrix1 temp(rows,cols,0);
			for(int i = 0; i < rows; i++) {
				for(int j = 0; j < cols; j++) {
					for(int k = 0; k < m._rows; k++) {
						temp._matrix[i][j] += this->_matrix[i][k] * m._matrix[k][j];
					}
				}
			}
			return temp;
		} else {
			intmatrix1 temp(0,0,0);
			return temp;
		}
	}
		
