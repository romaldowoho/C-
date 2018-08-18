#ifndef BASEPLUSCOMMISSIONEMPLOYEE_H
#define BASEPLUSCOMMISSIONEMPLOYEE_H

#include "../util/util.h"
#include "commissionemployee.h"

class basepluscommissionemployee : public commissionemployee {
private:
	char* _w;
	double _s;

public:
	basepluscommissionemployee(char* fn = "", char* ln = "", char* ssn = "", char* comm_giver = "", double commission = NULL, char* base_giver = "", double base = NULL);

	~basepluscommissionemployee();

	basepluscommissionemployee(const basepluscommissionemployee &copy);

	basepluscommissionemployee &operator=(const basepluscommissionemployee &rhs);

	friend ostream &operator<<(ostream &o, const basepluscommissionemployee &e);

	virtual void print(ostream &o) const;
};


#endif