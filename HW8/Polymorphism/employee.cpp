#include "employee.h"

	bool employee::_show = false;

	employee::employee(char* firstName, char* lastName, char* ssn) {
		if(_show) {
			cout << "employee constructor" << endl;
		}
		_f = firstName; 
		_l = lastName;
		_s = ssn;
	}

	employee::~employee() {
		if(_show) {
			cout << "employee destructor" << endl;
		}
	}

	employee::employee(const employee &copy) {
		if(_show) {
			cout << "employee copy constructor" << endl;
		}
		_f = copy._f;
		_l = copy._l;
		_s = copy._s;
	}
	

	employee &employee::operator=(const employee &rhs) {
		if(_show) {
			cout << "employee = operator" << endl;
		}
		if(&rhs != this) {
			_f = rhs._f;
			_l = rhs._l;
			_s = rhs._s;
		}
		return *this;
	}

	void employee::print(ostream &o) const {
		o << _f << " " << _l << " " << _s << " ";
		//return o;
	}

	ostream &operator<<(ostream &o, const employee &e) {
		e.print(o);
		return o;
	} 

