#include <iostream>
#include <climits>
using namespace std;

int price[9] = {0, 1, 5, 8, 9, 10, 17, 17, 20};
 int cut=0;
int CUT_ROD(int n) {
    ++cut;
    if (n == 0) return 0;

    int q = INT_MIN;
    for (int i = 1; i <= n; i++) {
        q = max(q, price[i] + CUT_ROD(n - i));
    }
    return q;
}

int main() {
    int n = 8;
    cout << "Maximum Revenue = " << CUT_ROD(n) << endl;
    cout << "Maximum Revenue = " << cut << endl;

    return 0;
}

