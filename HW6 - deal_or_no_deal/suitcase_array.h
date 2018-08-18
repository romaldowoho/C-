#ifndef SUITCASE_ARRAY_H
#define SUITCASE_ARRAY_H

#include "../util/util.h"
#include "suitcase.h"
#include <random>
#include <ctime>

class suitcase_array {
public:
	suitcase_array();
	~suitcase_array();
	void print() const;
	void randomize();
	void cross_out_value(string s);
	suitcase& get_suitcase(int k);
	friend class game;
private:
	suitcase _arr[26];
	string _values[26] = {"0.01", "1", "5", "10", "25", "50", "75", "100", "200", "300", "400", "500", "750", "1000", "5000", "10000", "25000", "50000", "75000", "100000", "200000", "300000", "400000", "500000", "750000", "1000000"};
	string _numbers[26] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26"};
};

#endif