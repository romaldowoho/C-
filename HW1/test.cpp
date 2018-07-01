#include "../util/util.h"

void a1(int a, int b) {
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

void a2(int a, int b) {
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

void a3(int a, int b) {
	auto range = b - a;
	for (auto i = 0; i <= range; i++) {
		for(auto k = a; k <= b; k++) {
			cout << k << " ";
		}
		b--;
		cout << endl;
	}
}

void a4(int a, int b) {
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

void riceOnChessBoard(int n) {
	cout << 'n' << " " << "rice on square n" << endl;
	for (int i = 1; i <= n; i++) {
		long long result = 1;
		for (int k = 0; k < i-1; k++) {
			result *= 2;
		}
		if (i == 1) {result = 1;}
		cout << i << " " << result << endl;
	}
}

int main(){
a1(3,8);
a2(3,8);
cout << endl;
a3(3,8);
a4(3,8);	
riceOnChessBoard(12);
}
