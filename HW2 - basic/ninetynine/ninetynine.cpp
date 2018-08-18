#include "ninetynine.h"
#include "../util/util.h"


void ninetynine::run() {
	string ones[] = {"nine", "eight", "seven", "six", "five", "four", "three", "two", "one", ""};
	string zero[] = {"Nine", "Eight", "Seven", "Six", "Five", "Four", "Three", "Two", "One", "Zero"};
	string tens[] = {"Ninety", "Eighty", "Seventy", "Sixty", "Fifty", "Forty", "Thirty", "Twenty"};
	string teeens[] = {"Nineteen", "Eighteen", "Seventeen", "Sixteen", "Fifteen", "Fourteen", "Thirteen", "Twelve", "Eleven", "Ten"};

	for(int i = 0; i < 8; i++) {
		for (int j = 0; j < 10; j++) {
			cout << tens[i] << " " << ones[j] << " bottles of beer on the wall," << endl;
			cout << tens[i] << " " << ones[j] << " bottles of beer," << endl;
			int k = j + 1;
			if(j == 9) continue;
			cout << "Take one down, pass it around," << endl;
			cout << tens[i] << " " << ones[k] << " bottles of beer on the wall," << endl;
			cout << endl;
		}
	}

	cout << "Take one down, pass it around," << endl;
	cout << "Nineteen bottles of beer on the wall," << endl;
	cout << endl;

	for(int i = 0; i < 10; i++) {
		cout << teeens[i] << " bottles of beer on the wall," << endl;
		cout << teeens[i] << " bottles of beer," << endl;
		int k = i + 1;
		if(i == 9) {
			cout << "Take one down, pass it around," << endl;
			cout << "Nine bottles of beer on the wall," << endl;
			cout << endl;
		}
		cout << "Take one down, pass it around," << endl;
		cout << teeens[k] << " bottles of beer on the wall," << endl;
		cout << endl;
	}

	for(int i = 0; i < 10; i++) {
		if (i == 8) {
			cout << zero[i] << " bottle of beer on the wall," << endl;
			cout << zero[i] << " bottle of beer," << endl;
			int k = i + 1;
			cout << "Take one down, pass it around," << endl;
			cout << zero[k] << " bottles of beer on the wall," << endl;
			cout << endl;
			break;
		}
		cout << zero[i] << " bottles of beer on the wall," << endl;
		cout << zero[i] << " bottles of beer," << endl;
		int k = i + 1;
		if(i == 9) continue;
		cout << "Take one down, pass it around," << endl;
		if (k==8) {
			cout << zero[k] << " bottle of beer on the wall," << endl;
			cout << endl;
			continue;
		}
		cout << zero[k] << " bottles of beer on the wall," << endl;
		cout << endl;
	} 
}