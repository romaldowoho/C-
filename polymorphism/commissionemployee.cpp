#include "commissionemployee.h"

commissionemployee::commissionemployee(char* fn, char* ln, char* ssn, char* who, double salary) 
: employee(fn,ln,ssn) {
	if(_show) {
		cout << "commissionemployee constructor" << endl;
	}
	_w = who;
	_s = salary;
}

commissionemployee::~commissionemployee() {
	if(_show) {
		cout << "commissionemployee destructor" << endl;
	}
}

commissionemployee::commissionemployee(const commissionemployee &copy) : employee(copy) {
	if(_show) {
		cout << "commissionemployee copy constructor" << endl;
	}
	_w = copy._w;
	_s = copy._s;
}

commissionemployee &commissionemployee::operator=(const commissionemployee &rhs) {
	if(_show) {
		cout << "commissionemployee = operator" << endl;
	}
	if(this != &rhs) {
		employee::operator=(rhs);
		_w = rhs._w;
		_s = rhs._s;
	}
	return *this;
}

void commissionemployee::print(ostream &o) const {
	this->employee::print(o);
	o << _w << " " << _s << " ";
}

ostream &operator<<(ostream &o, const commissionemployee &e) {
		e.print(o);
		return o;
	} 