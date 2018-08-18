#include "salariedemployee.h"

salariedemployee::salariedemployee(char* fn, char* ln, char* ssn, char* who, double salary) 
: employee(fn,ln,ssn) {
	if(_show) {
		cout << "salariedemployee constructor" << endl;
	}
	_w = who;
	_s = salary;
}

salariedemployee::~salariedemployee() {
	if(_show) {
		cout << "salariedemployee destructor" << endl;
	}
}

salariedemployee::salariedemployee(const salariedemployee &copy) : employee(copy) {
	if(_show) {
		cout << "salariedemployee copy constructor" << endl;
	}
	_w = copy._w;
	_s = copy._s;
}

salariedemployee &salariedemployee::operator=(const salariedemployee &rhs) {
	if(_show) {
		cout << "salariedemployee = operator" << endl;
	}
	if(&rhs != this) {
		employee::operator=(rhs);
		_w = rhs._w;
		_s = rhs._s;
	}
	return *this;
}

void salariedemployee::print(ostream &o) const {
	this->employee::print(o);
	o << _w << " " << _s << " ";
}

ostream &operator<<(ostream &o, const salariedemployee &e) {
		e.print(o);
		return o;
	} 