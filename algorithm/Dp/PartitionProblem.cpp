// dp[i][j] = dp[i-1][j] || dp[i-1][j-a[j]];
//
// dp[k][i][j] = dp[k-1][i-1][j-a[j]]||dp[k][i-1][j]
//

bool isSubSetSum(int a[]. int n, int sum) {
	bool subSet[n+1][sum+1];
	for (int i = 0; i <= n; i++) {
		subSet[i][0] = true;
	}

	for (int i = 1; i <= sum; i++) {
		subSet[0][i] = false;
	}

	for (int i = 1; i <= sum; i++) {
		for (int j = 1; j <= n; j++) {
			subSet[j][i] = sum[j-1][i];
			if (i > a[i-1]) {
				subSet[j][i] = subSet[j][i] ||subSet[j-1][i-a[i-1]];
			}
		}
	}

	return subSet[n][sum];
}
