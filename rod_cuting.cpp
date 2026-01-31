#include <iostream>
#include <climits>
using namespace std;

void extended_bottom_up_cut_rod(int p[], int n, int r[], int s[]) {
    r[0] = 0;
    for (int j = 1; j <= n; j++) {
        int q = INT_MIN;
        for (int i = 1; i <= j; i++) {
            if (q < p[i] + r[j - i]) {
                q = p[i] + r[j - i];
                s[j] = i;

            }
        }
        r[j] = q;


        cout << "Length " << j << " => Max Revenue: " << r[j]
             << " (First cut: " << s[j]<< ")\n";
    }
}

void print_cut_rod_solution(int p[], int n) {
    int r[100], s[100]; //
    extended_bottom_up_cut_rod(p, n, r, s);

    cout << "\nFinal Maximum Revenue: " << r[n] << "\n";
    cout << "Cuts sequence: ";
    int temp = n;
    while (temp > 0) {
        cout << s[temp] << " ";
        temp -= s[temp];
    }
    cout << "\n";

    cout << "\nRevenue Table (r[]):\n";
    for (int j = 0; j <= n; j++) cout << r[j] << " ";
    cout << "\n";

    cout << "Cut Table (s[]):\n";
    for (int j = 0; j <= n; j++) cout << s[j] << " ";
    cout << "\n";
}

int main() {
    int p[11] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30}; // length 0..10
    int n = 10;

    print_cut_rod_solution(p, n);

    return 0;
}
