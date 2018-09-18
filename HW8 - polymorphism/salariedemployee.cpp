#include "salariedemployee.h"

salariedemployee::salariedemployee(char* fn, char* ln, char* ssn, char* who, double salary) 
: employee(fn,ln,ssn) {
	if(_show) {
		cout << "salariedemployee constructor" << endl;
	}
	_alloc(who,salary);
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
	_copy(copy);
}

salariedemployee &salariedemployee::operator=(const salariedemployee &rhs) {
	if(_show) {
		cout << "salariedemployee = operator" << endl;
	}
	if(&rhs != this) {
		employee::operator=(rhs);
		_free();
		_copy(rhs);
	}
	return *this;
}

void salariedemployee::_alloc(char *who, double salary) {
	_w = new char[strlen(who) + 1];
	strcpy(_w,who);
	_s = salary;
}

void salariedemployee::_copy(const salariedemployee &copy) {
	_w = new char[strlen(copy._w) + 1];
	strcpy(_w,copy._w);
	_s = copy._s; 
}

void salariedemployee::_free() {
	delete [] _w;
}

void salariedemployee::print(ostream &o) const {
	this->employee::print(o);
	o << _w << " " << _s << " ";
}

ostream &operator<<(ostream &o, const salariedemployee &e) {
		e.print(o);
		return o;
	} 