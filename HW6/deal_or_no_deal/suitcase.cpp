#include "suitcase.h"

suitcase::suitcase(string num, string val) {
	_number = num;
	_value = val;
}

suitcase::~suitcase() {

}

void suitcase::set_num(string num) {
	_number = num;
}

void suitcase::set_val(string val) {
	_value = val;
}

string suitcase::get_num() const {
	return _number;
}

string suitcase::get_val() const {
	return _value;
}

void suitcase::reserve() {
	_number = " ";
}
void suitcase::print_suitcase() const {
	cout << _number << endl;
}

void suitcase::open() {
	set_val("-");
	set_num("-");
}

suitcase& suitcase::operator=(const suitcase& rhs) {
	if(this != &rhs) {
		_number = rhs._number;
		_value = rhs._value;
	}
	return *this;
}