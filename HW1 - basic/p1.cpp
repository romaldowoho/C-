#include "p1.h"
#include "../util/util.h"

void p1::print_usa() {
cout << " x     x   xxx      x" << endl;
cout << " x     x  x   x    x x" << endl;
cout << " x     x  x       x   x" << endl;
cout << " x     x    x     xxxxx" << endl;
cout << " x     x     x   x     x" << endl;
cout << " xx   xx  x   x  x     x" << endl;
cout << "   xxx     xxx   x     x" << endl;
}

void p1::print_n_n2_n3() {
	cout << "n  n^2  n^3" << endl;
	auto n2 = 0, n3 = 0;
	for(int i = 1; i < 10; i++) {
		n2 = i*i;
		n3 = i*i*i;
		if(i < 4) {
			cout << i << "  " << n2 << "    " << n3 << endl;
		} else {
			  cout << i << "  " << n2 << "   " << n3 << endl;
		  }
	}
}

void p1::a_power_b() {
	cout << 'a' << " " << 'b' << " " << "a^b" << endl;
	for (int a = 1; a < 8; a++) {
		auto ab = 1;
		for (int k = 0; k <= a; k++) {
			ab *= a;
		}
		cout << a << " " << a+1 << " " << ab << endl;
	}
}

void p1::two_power_n() {
cout << 'n' << " " << "2^n" << endl;
cout << 0 << " " << 1 << endl;
	for (int i = 1; i < 21; i++) {
		auto result = 1;
		for(int k = 0; k < i; k++) {
			result *= 2;
		}
		cout << i << " " << result << endl;
	}
}

void p1::a1(int a, int b) {
	auto range = b - a;
	auto k = a + 1;
	for (auto i = 0; i <= range; i++) {
		for (auto j = a; j < k; j++) {
			cout << j << " ";
		}
		k++;
		cout << endl;
	}
}

void p1::a2(int a, int b) {
	auto range = b - a;
	auto line = range;
	for (auto i = a; i <= b; i++) {
		for (auto j = line; j > 0; j--) {
			cout << "  ";
		}
		for (auto k = i; k >= a; k--) {
			cout << k << " ";
		}
		line--;
		cout << endl;
	}
}

void p1::a3(int a, int b) {
	auto range = b - a;
	for (auto i = 0; i <= range; i++) {
		for(auto k = a; k <= b; k++) {
			cout << k << " ";
		}
		b--;
		cout << endl;
	}
}

void p1::a4(int a, int b) {
	auto space = 0;
	auto bb = b;
	for (auto i = a; i <= b; i++) {
		for (auto j = 0; j < space; j++) {
			cout << "  ";
		}
		space++;
		for (auto k = a; k <= bb; k++) {
			cout << k << " ";
		}
		bb--;
		cout << endl;
	}

}

void p1::riceOnChessBoard(int n) {
	cout << 'n' << " " << "rice on square n" << endl;
	for (int i = 1; i <= n; i++) {
		long long result = 1;
		for (int k = 0; k < i-1; k++) {
			result *= 2;
		}
		if (i == 1) {result = 1;}
		if (i == 64) {result -= 1;}
		cout << i << " " << result << endl;
	}
}














