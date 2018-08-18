#ifndef SUITCASE_H
#define SUITCASE_H

#include "../util/util.h" 

class suitcase {
public:
	//suitcase();
	suitcase(string num = "", string val = "");
	~suitcase();
	void set_num(string num);
	void set_val(string val);
	string get_num() const;
	string get_val() const;
	void open();
	void print_suitcase() const;
	void reserve();
	suitcase& operator=(const suitcase& rhs);
private:
	string _number;
	string _value;
};

#endif