#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int weight;
    int value;
};

bool compareItems(const Item& a, const Item& b) {
    double ratioA = (double)a.value / a.weight;
    double ratioB = (double)b.value / b.weight;
    return ratioA > ratioB;
}

int knapsackGreedy(vector<Item>& items, int W) {
    sort(items.begin(), items.end(), compareItems);
    int n = items.size();
    int totalValue = 0;
    int currentWeight = 0;

    for (int i = 0; i < n; ++i) {
        if (currentWeight + items[i].weight <= W) {
            totalValue += items[i].value;
            currentWeight += items[i].weight;
        }
    }

    return totalValue;
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

    int maxValue = knapsackGreedy(items, W);
    cout << "Gia tri max co the dat duoc: " << maxValue << endl;

    return 0;
}

