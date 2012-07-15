// Coin Change is the problem of finding the number of ways of making changes for a particular amount of cents, n
// using a given set of denominations . 
// It is a general case of Integer Partition, and can be solved with dynamic programming. 
// (The Min-Coin Change is a common variation of this problem.)
//
//
//
// we can formulate the following:
//
//C(N,m) = C(N,m - 1) + C(N - Sm,m)
//
#include <iostream>
using namespace std;
int count(int*s, int m, int n) {
    if (n == 0) {
        return 1;
    }
    if (n < 0) {
        return 0;
    }

    if ( m <=0 && n>= 1) {
        return 0;
    }

    return count(s, m-1, n) + count(s, m, n - s[m-1]);
}

/*
#include <iostream>
using namespace std;
int makeChange(int n, int demon) {
	int next_demon = 0;
	switch (demon) {
	case 25:
		next_demon = 10;
		break;
	case 10:
		next_demon = 5;
		break;
	case 5:
		next_demon = 1;
		break;
	case 1:
		return 1;
	default:
		break;
	}
	int ways = 0;
	for (int i = 0; i * demon <= n; i++) {
		ways += makeChange(n-i*demon, next_demon);
	}
	return ways;
}
*/
int main() {
    int s[4] = {1, 5, 10, 25};
	//int n = count(s, 4, 100);
    int r[101][4];
    for (int j = 0; j < 4; j++) {
        r[0][j] = 1;
    }

    for (int i = 1; i < 101; i++) {
        for (int j = 0; j < 4; j++) {
            int x;int y;
            x = (i >= s[j])?r[i-s[j]][j]:0;
            y = (j>=1)?r[i][j-1]:0;
            r[i][j] = x + y;
        }
    }
    cout << r[100][3] << endl;
}
