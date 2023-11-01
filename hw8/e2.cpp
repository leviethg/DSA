#include <iostream>
#include <vector>

using namespace std;

struct Item {
    int weight;
    int value;
};

int knapsack(vector<Item>& items, int W) {
    int n = items.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (items[i - 1].weight <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - items[i - 1].weight] + items[i - 1].value);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
	for (int i = 0; i <=n; ++i) {
		for (int w = 0; w <= W; ++w) {
			if (w < W) {
			cout << dp[i][w] << " "; } else cout << dp[i][w] << endl;
		}
	}
    return dp[n][W];
}

int main() {
    int W, N;
    cout << "Nhap suc chua cua balo (W): ";
    cin >> W;

    cout << "Nhap so luong vat pham (N): ";
    cin >> N;

    vector<Item> items(N);

    for (int i = 0; i < N; i++) {
        cout << "Nhap khoi luong va gia tri cua vat pham " << i + 1 << ": ";
        cin >> items[i].weight >> items[i].value;
    }
	
	cout << endl;
	
    int maxValue = knapsack(items, W);
    cout << "Gia tri max co the dat duoc: " << maxValue << endl;

    return 0;
}

