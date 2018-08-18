#ifndef SALARIEDEMPLOYEE_H
#define SALARIEDEMPLOYEE_H

#include "../util/util.h"
#include "employee.h"

class salariedemployee : public employee {
private:
	char* _w;
	double _s;

public:
	salariedemployee(char* fn = "", char* ln = "", char* ssn = "", char* who = "", double salary = NULL);

	~salariedemployee();

	salariedemployee(const salariedemployee &copy);

	salariedemployee &operator=(const salariedemployee &rhs);

	friend ostream &operator<<(ostream &o, const salariedemployee &e);

	virtual void print(ostream &o) const;
};


#endif