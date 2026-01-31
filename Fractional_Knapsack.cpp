#include <iostream>
using namespace std;

void swapDouble(double &a, double &b) {
    double temp = a;
    a = b;
    b = temp;
}

void swapInt(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void sortByRatio(int n, int w[], int v[], double ratio[]) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                swapDouble(ratio[i], ratio[j]);
                swapInt(w[i], w[j]);
                swapInt(v[i], v[j]);
            }
        }
    }
}

int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter knapsack capacity: ";
    cin >> W;

    int w[100], v[100];
    double ratio[100];

    cout << "Enter weights and values of items:\n";
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
        ratio[i] = (double)v[i] / w[i];
    }

    sortByRatio(n, w, v, ratio);

    double totalValue = 0.0;
    int remaining = W;

    cout << "Items taken:\n";
    for (int i = 0; i < n; i++) {
        if (w[i] <= remaining) {
            totalValue += v[i];
            remaining -= w[i];
            cout << "Take full item " << i + 1 << endl;
        } else {
            totalValue += ratio[i] * remaining;
            cout << "Take " << remaining << " weight of item " << i + 1 << endl;
            remaining = 0;
            break;
        }
    }

    cout << "Maximum value obtainable: " << totalValue << endl;

    return 0;
}
