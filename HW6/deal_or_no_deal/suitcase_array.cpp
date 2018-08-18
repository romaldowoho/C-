#include "suitcase_array.h"

suitcase_array::suitcase_array() {
	for(int i = 0; i < 26; i++) {
		suitcase temp(_numbers[i], _values[i]);
		_arr[i] = temp;
	}
	randomize();
}

suitcase_array::~suitcase_array() {

}

void suitcase_array::randomize() {
	default_random_engine generator;
	generator.seed(time(0));
	uniform_int_distribution<int> distribution(0,25);
	for (int i = 0; i < 1000; i++) {
		int a = distribution(generator);
		int b = distribution(generator);
		string temp = _arr[a].get_val();
		_arr[a].set_val(_arr[b].get_val());
		_arr[b].set_val(temp);
	}	
}

void suitcase_array::print() const {
	cout << "--- Suitcases --- " << endl;
	for(int i = 0; i < 26; i++) {
		if(i < 10) {
			cout << _arr[i].get_num() << "  ";
		} else {
			cout << _arr[i].get_num() << " ";
		}
		if(i % 5 == 0 && i != 0) cout << endl;
	}
	cout << endl;
	for(int i = 0; i < 26; i++) {
		cout << _values[i] << " ";
		if(i == 12) cout << endl;
	}
	cout << endl << endl;
}

void suitcase_array::cross_out_value(string s) {
	for (int i = 0; i < 26; i++) {
		if(_values[i] == s) {
			_values[i] = "-";
		}
	}
}

suitcase& suitcase_array::get_suitcase(int k) {
	return _arr[k - 1];
}