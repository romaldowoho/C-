#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "../util/util.h"

class employee {
protected:
	char* _f;
	char* _l;
	char* _s;
	static bool _show;

public:
	employee(char* firstName = "", char* lastName = "", char* ssn = "");

	virtual ~employee();

	employee(const employee &copy);

	employee &operator=(const employee &rhs);

	friend ostream &operator<<(ostream &o, const employee &e);

	bool static setShow(bool show) {
		_show = show;
	}

	virtual void print(ostream &o) const;

private:
	void _alloc(char *firstName, char *lastName, char *ssn);
	void _copy(const employee &copy);
	void _free();
};


#endif