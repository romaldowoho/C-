#include "employee.h"

	bool employee::_show = false;

	employee::employee(char* firstName, char* lastName, char* ssn) {
		if(_show) {
			cout << "employee constructor" << endl;
		}
		_alloc(firstName,lastName,ssn);
	}

	employee::~employee() {
		if(_show) {
			cout << "employee destructor" << endl;
		}
		_free();
	}

	employee::employee(const employee &copy) {
		if(_show) {
			cout << "employee copy constructor" << endl;
		}
		_copy(copy);
	}
	

	employee &employee::operator=(const employee &rhs) {
		if(_show) {
			cout << "employee = operator" << endl;
		}
		if(&rhs != this) {
			_free();
			_copy(rhs);
		}
		return *this;
	}

	void employee::_alloc(char *firstName, char *lastName, char *ssn) {
		_f = new char[strlen(firstName) + 1];
		strcpy(_f,firstName);

		_l = new char[strlen(lastName) + 1];
		strcpy(_l,lastName);

		_s = new char[strlen(ssn) + 1];
		strcpy(_s,ssn);
	}

	void employee::_copy(const employee &copy) {
		_f = new char[strlen(copy._f) + 1];
		strcpy(_f,copy._f);

		_l = new char[strlen(copy._l) + 1];
		strcpy(_l,copy._l);

		_s = new char[strlen(copy._s) + 1];
		strcpy(_s,copy._s);
	}

	void employee::_free() {
		delete [] _f;
		delete [] _l;
		delete [] _s;
	}

	void employee::print(ostream &o) const {
		o << _f << " " << _l << " " << _s << " ";
		//return o;
	}

	ostream &operator<<(ostream &o, const employee &e) {
		e.print(o);
		return o;
	} 

