#include <iostream>
using namespace std;

int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter knapsack capacity: ";
    cin >> W;

    int w[100], v[100];
    cout << "Enter weights of items:\n";
    for (int i = 0; i < n; i++) cin >> w[i];

    cout << "Enter values of items:\n";
    for (int i = 0; i < n; i++) cin >> v[i];

    int dp[101][1001] = {0};

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (w[i - 1] <= j) {
                dp[i][j] = max(dp[i - 1][j], v[i - 1] + dp[i - 1][j - w[i - 1]]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << "Maximum value that can be obtained: " << dp[n][W] << endl;

    cout << "Items selected (1-based index): ";
    int j = W;
    for (int i = n; i > 0; i--) {
        if (dp[i][j] != dp[i - 1][j]) {
            cout << i << " ";
            j -= w[i - 1];
        }
    }
    cout << endl;

    return 0;
}

