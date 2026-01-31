#include <iostream>
using namespace std;


void sortActivities(int s[], int f[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (f[j] < f[minIndex]) {
                minIndex = j;
            }
        }

        int tempF = f[i];
        f[i] = f[minIndex];
        f[minIndex] = tempF;

        int tempS = s[i];
        s[i] = s[minIndex];
        s[minIndex] = tempS;
    }
}

void GreedyActivitySelector(int s[], int f[], int n) {
    cout << "Selected activities (Greedy): ";
    int k = 0;
    cout << "a" << k + 1 << " ";

    for (int m = 1; m < n; m++) {
        if (s[m] >= f[k]) {
            cout << "a" << m + 1 << " ";
            k = m;
        }
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of activities: ";
    cin >> n;

    int s[n], f[n];
    cout << "Enter start times of activities:\n";
    for (int i = 0; i < n; i++) cin >> s[i];

    cout << "Enter finish times of activities:\n";
    for (int i = 0; i < n; i++) cin >> f[i];

    sortActivities(s, f, n);

    cout << "\nActivities after sorting by finish time:\n";
    cout << "Activity\tStart\tFinish\n";
    for (int i = 0; i < n; i++) {
        cout << "a" << i + 1 << "\t\t" << s[i] << "\t" << f[i] << endl;
    }

    cout << endl;


    GreedyActivitySelector(s, f, n);

    return 0;
}
