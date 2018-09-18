#ifndef COMMISSIONEMPLOYEE_H
#define COMMISSIONEMPLOYEE_H

#include "../util/util.h"
#include "employee.h"

class commissionemployee : public employee {
protected:
	char* _w;
	double _s;

public:
	commissionemployee(char* fn = "", char* ln = "", char* ssn = "", char* who = "", double commission = NULL);

	virtual ~commissionemployee();

	commissionemployee(const commissionemployee &copy);

	commissionemployee &operator=(const commissionemployee &rhs);

	friend ostream &operator<<(ostream &o, const commissionemployee &e);

	virtual void print(ostream &o) const;

private:
	void _alloc(char *who, double salary);
	void _copy(const commissionemployee &copy);
	void _free();
};


#endif