
#include <iostream>
#include <climits>
using namespace std;

int price[9] = {0, 1, 5, 8, 9, 10, 17, 17, 20};
int memo[100];
  int cut=0;
int MEMOIZED_CUT_ROD_AUX(int n) {
      ++cut;
    if (memo[n] >= 0) return memo[n];
    int q;
    if (n == 0) q = 0;
    else {
        q = INT_MIN;
        for (int i = 1; i <= n; i++) {
            q = max(q, price[i] + MEMOIZED_CUT_ROD_AUX(n - i));
        }
    }
    memo[n] = q;
    return q;
}

int MEMOIZED_CUT_ROD(int n) {
    for (int i = 0; i <= n; i++) memo[i] = -1;
    return MEMOIZED_CUT_ROD_AUX(n);
}

int main() {
    int n = 8;
    cout << "Maximum Revenue = " << MEMOIZED_CUT_ROD(n) << endl;
    cout << "Maximum Revenue = " << cut<< endl;

    return 0;
}
