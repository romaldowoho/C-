#include "commissionemployee.h"

commissionemployee::commissionemployee(char* fn, char* ln, char* ssn, char* who, double salary) 
: employee(fn,ln,ssn) {
	if(_show) {
		cout << "commissionemployee constructor" << endl;
	}
	_alloc(who, salary);
}

commissionemployee::~commissionemployee() {
	if(_show) {
		cout << "commissionemployee destructor" << endl;
	}
	_free();
}

commissionemployee::commissionemployee(const commissionemployee &copy) : employee(copy) {
	if(_show) {
		cout << "commissionemployee copy constructor" << endl;
	}
	_copy(copy);
}

commissionemployee &commissionemployee::operator=(const commissionemployee &rhs) {
	if(_show) {
		cout << "commissionemployee = operator" << endl;
	}
	if(this != &rhs) {
		employee::operator=(rhs);
		_free();
		_copy(rhs);
	}
	return *this;
}

void commissionemployee::_alloc(char *who, double salary) {
	_w = new char[strlen(who) + 1];
	strcpy(_w,who);
	_s = salary;
}

void commissionemployee::_copy(const commissionemployee &copy) {
	_w = new char[strlen(copy._w) + 1];
	strcpy(_w,copy._w);
	_s = copy._s; 
}

void commissionemployee::_free() {
	delete [] _w;
}

void commissionemployee::print(ostream &o) const {
	this->employee::print(o);
	o << _w << " " << _s << " ";
}

ostream &operator<<(ostream &o, const commissionemployee &e) {
		e.print(o);
		return o;
	} 