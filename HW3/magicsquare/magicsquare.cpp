#include "magicsquare.h"
#include "../util/util.h"

void magicsquare::print_magic_square(int n) {
	int **ppArray = new int*[n];
	for (int i = 0; i < n; i++) {
		ppArray[i] = new int[n];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ppArray[i][j] = 0;
		}
	}

	int r = 0;
	int c = n/2;

	for (int i = 1; i <= n*n; i++) {
		ppArray[r][c] = i;
		//now we need to prepare r and c values for the next iteration
		if(i == 1) {
			r = n - 1;
			c -= 1;
			continue;
		}
		//margins
		if((r - 1 < 0 || c - 1 < 0) && c != r) {
			int maxDim = max(r,c);
			if (maxDim == r) {
				r -= 1;
				c = n - 1;
				continue;
			} else {
				c -= 1;
				r = n - 1;
				continue;
			}
		} 
		// fall down cases: upper left corner and when upper left cell is not empty 
		else if((r - 1 < 0 && c - 1 < 0) || (ppArray[r - 1][c - 1] != 0)) {
			r += 1;
			continue;
		} 

		r -= 1;
		c -= 1;
	}
 	
 	if (n < 12) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if(ppArray[i][j] < 10) {
					cout << " " << ppArray[i][j] << " ";
				} else cout << ppArray[i][j] << " ";
			}
			cout << endl;
		} cout << endl;
	} else {
		int sum = 0;
		int sum2 = 0;
		for (int i = 0; i < n; i++) {
			sum += ppArray[0][i];
		}
		cout << "The sum is: " << sum << endl;
	}	
}