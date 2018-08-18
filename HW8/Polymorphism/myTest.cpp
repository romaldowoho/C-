#include "salariedemployee.h"

using namespace std;

int main() {
	employee::setShow(true);
	employee emp("Roma", "Ushp", "55");
	salariedemployee sEmp("Roma", "Ushp", "55", "Health IQ", 90000);
	salariedemployee sEmp2(sEmp);
	cout << emp << endl;
	cout << sEmp << endl;
	cout << sEmp2 << endl;
	return 0;
}