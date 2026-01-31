
#include <iostream>
#include <climits>
using namespace std;

int price[9] = {0, 1, 5, 8, 9, 10, 17, 17, 20};

void EXTENDED_BOTTOM_UP_CUT_ROD(int n) {
    int r[100], s[100];
    r[0] = 0;

    for (int j = 1; j <= n; j++) {
        int q = INT_MIN;
        for (int i = 1; i <= j; i++) {
            if (q < price[i] + r[j - i]) {
                q = price[i] + r[j - i];
                s[j] = i;
            }
        }
        r[j] = q;
    }

    cout << "Maximum Revenue = " << r[n] << endl;

    cout << "Optimal Cuts: ";
    while (n > 0) {
        cout << s[n] << " ";
        n -= s[n];
    }
    cout << endl;
}

int main() {
    int n = 8;
    EXTENDED_BOTTOM_UP_CUT_ROD(n);
    return 0;
}
