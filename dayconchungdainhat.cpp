#include <bits/stdc++.h>

using namespace std;

int lcs (string A, string B, int m, int n) {
	int dp[m+1][n+1];
	
	for (int i = 0; i <= m; ++i) {
		for (int j = 0; j <= n; ++j) {
			if (i == 0 || j == 0) {
				dp[i][j] = 0;
			}
			else if (A[i - 1] == B[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	
	return dp[m][n];
}

int main() {
	string A, B;
	cout << "Day A la: ";
	cin >> A;
	cout << "Day B la: ";
	cin >> B;

	int m = A.size(), n = B.size();
	cout << "Do dai day con chung dai nhat cua A va B la: " << lcs(A, B, m, n);
	
	return 0;
}
