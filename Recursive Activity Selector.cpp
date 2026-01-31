#include <iostream>
using namespace std;

void RecursiveActivitySelector(int s[], int f[], int k, int n) {
    int m = k + 1;

    while (m <= n && s[m] < f[k])
        m++;

    if (m <= n) {
        cout << "a" << m << " ";
        RecursiveActivitySelector(s, f, m, n);
    }
}

int main() {
    int s[] = {0, 1, 3, 0, 5, 8, 5};
    int f[] = {0, 4, 5, 6, 7, 9, 9};
    int n = 6;

    cout << "Selected activities (Recursive): ";
    RecursiveActivitySelector(s, f, 0, n);
    cout << endl;

    return 0;
}

