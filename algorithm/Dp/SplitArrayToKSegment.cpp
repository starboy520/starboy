#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;
/**
 * Give an array of non-negative integers A, and a positive number k,
 * Split the array into K  partitions, such that the maximum sum over
 * all the partitions is minimized.
 *
 * dp[i, k] 0-i element split to k partition, max sum is minimized.
 *
 * dp[i, k] = min max(dp[j, k-1], sum(j+1, i)); { 0 <= j <= i }
*/

int findMax(int* a, int n, int k) {
	vector< vector<int> > dp(n+1, vector<int>(n+1, 0));
	vector<int> sum(n+1, 0);
	//int dp[n+1][k+1] = {0};
	//int sum[n+1] = {0};

	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i-1] + a[i-1];
	}

	for (int i = 1; i <= n; i++) {
		dp[i][1] = sum[i];
	}

	for (int i = 1; i <= k; i++) {
		dp[1][i] = a[0];
	}

	for (int i = 2; i <= k; i++) {
		for (int j = 2; j <= n; j++) {
			int best = INT_MAX;
			for (int p = 1; p <= j; p++) {
				best = min(best, max(dp[p][i-1], sum[j]-sum[p]));
			}
			dp[j][i] = best;
		}
	}
	return dp[n][k];
}

int getMAx(int *a, int n) {
	int max = INT_MIN;
	for (int i = 0; i < n; i++) {
		if (a[i] > max) max = a[i];
	}
	return max;
}

int getSum(int a[], int n) {
	int total = 0;
	for (int i = 0; i < n; i++) total += a[i];
	return total;
}

int getRequired(int a[], int n, int maxLen) {
	int total = 0;
	int num = 1;
	for (int i = 0; i < n; i++) {
		total += a[i];
		if (total > maxLen) {
			total = a[i];
			num++;
		}
	}
	return num;
}

int partition(int a[], int n, int k) {
	int lo = getMAx(a, n);
	int hi = getSum(a, n);

	while (lo < hi) {
		int mid = lo + (hi - lo)/2;
		int re = getRequired(a, n, mid);
		if (re <= k) {
			hi = mid;
		} else {
			lo = mid + 1;
		}
	}
	return lo;
}
int main() {
	int a[2] = {1,2};
	cout << findMax(a, 2, 1) << endl;
	cout << partition(a, 2, 1) << endl;
	return 0;
}
