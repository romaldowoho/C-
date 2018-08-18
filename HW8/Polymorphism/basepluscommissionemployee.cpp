#include "basepluscommissionemployee.h"

basepluscommissionemployee::basepluscommissionemployee(char* fn, char* ln, char* ssn, char* who, double salary, char* base_giver, double base) 
: commissionemployee(fn,ln,ssn,who,salary) {
	if(_show) {
		cout << "basepluscommissionemployee constructor" << endl;
	}
	_w = base_giver;
	_s = base;
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
	_w = copy._w;
	_s = copy._s;
}

basepluscommissionemployee &basepluscommissionemployee::operator=(const basepluscommissionemployee &rhs) {
	if(_show) {
		cout << "basepluscommissionemployee = operator" << endl;
	}
	if(this != &rhs) {
		commissionemployee::operator=(rhs);
		_w = rhs._w;
		_s = rhs._s;
	}
	return *this;
}

void basepluscommissionemployee::print(ostream &o) const {
	this->commissionemployee::print(o);
	o << _w << " " << _s << " ";
}

ostream &operator<<(ostream &o, const basepluscommissionemployee &e) {
		e.print(o);
		return o;
} 