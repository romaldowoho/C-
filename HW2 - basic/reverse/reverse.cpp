#include "reverse.h"
#include "..util/util.h"

unsigned long reverse1::r(unsigned long n) {
	unsigned long reverse = 0;
	while(n) {
		reverse *= 10;
		reverse += a % 10; 
		n /= 10;
	}
	if(reverse > 4294967295) reverse = 0;
	return reverse;
}

unsigned long reverse1::firstFail();