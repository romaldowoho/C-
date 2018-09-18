#include "basepluscommissionemployee.h"

basepluscommissionemployee::basepluscommissionemployee(char* fn, char* ln, char* ssn, char* who, double salary, char* base_giver, double base) 
: commissionemployee(fn,ln,ssn,who,salary) {
	if(_show) {
		cout << "basepluscommissionemployee constructor" << endl;
	}
	_alloc(base_giver, base);
}

basepluscommissionemployee::~basepluscommissionemployee() {
	if(_show) {
		cout << "basepluscommissionemployee destructor" << endl;
	}
}

basepluscommissionemployee::basepluscommissionemployee(const basepluscommissionemployee &copy) : commissionemployee(copy) {
	if(_show) {
		cout << "basepluscommissionemployee copy constructor" << endl;
	}
	_copy(copy);
}

basepluscommissionemployee &basepluscommissionemployee::operator=(const basepluscommissionemployee &rhs) {
	if(_show) {
		cout << "basepluscommissionemployee = operator" << endl;
	}
	if(this != &rhs) {
		commissionemployee::operator=(rhs);
		_free();
		_copy(rhs);
	}
	return *this;
}

void basepluscommissionemployee::_alloc(char *who, double salary) {
	_w = new char[strlen(who) + 1];
	strcpy(_w,who);
	_s = salary;
}
void basepluscommissionemployee::_copy(const basepluscommissionemployee &copy) {
	_w = new char[strlen(copy._w) + 1];
	strcpy(_w,copy._w);
	_s = copy._s; 
}
void basepluscommissionemployee::_free() {
	delete [] _w;
}

void basepluscommissionemployee::print(ostream &o) const {
	this->commissionemployee::print(o);
	o << _w << " " << _s << " ";
}

ostream &operator<<(ostream &o, const basepluscommissionemployee &e) {
		e.print(o);
		return o;
} 