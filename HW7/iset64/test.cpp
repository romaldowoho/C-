#include "iset64.h"
using namespace std;


int main() {
	int arr[] = {10,5,15,20};
	iset64 a;
	a += 64;
	a += 63;
	a = 1 + a;
	a = 10 + a;
	iset64 b(arr,sizeof(arr) / sizeof(int));
	iset64 c(arr,sizeof(arr) / sizeof(int));
	b = b + 1;
	c = c + 4;
	a.printSet();
	b.printSet();
	c.printSet();
	if(b==c) {
		cout << "Yes\n";
	} else cout << "No\n";
	++a;
	a.printSet();
}