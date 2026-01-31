
#include <iostream>
using namespace std;

int main() {
    int n, m;
    cout << "Enter number of processes: ";
    cin >> n;
    cout << "Enter number of resources: ";
    cin >> m;

    int alloc[n][m], maxNeed[n][m], avail[m];

    cout << "\nEnter Allocation Matrix (" << n << "x" << m << "):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> alloc[i][j];

    cout << "\nEnter Max Matrix (" << n << "x" << m << "):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> maxNeed[i][j];

    cout << "\nEnter Available Resources (" << m << "): ";
    for (int j = 0; j < m; j++)
        cin >> avail[j];

    int need[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            need[i][j] = maxNeed[i][j] - alloc[i][j];

    bool finish[n] = {false};
    int safeSeq[n], work[m];


    for (int i = 0; i < m; i++)
        work[i] = avail[i];

    int count = 0;

    while (count < n) {
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                bool possible = true;
                for (int j = 0; j < m; j++)
                    if (need[i][j] > work[j]) {
                        possible = false;
                        break;
                    }

                if (possible) {

                    for (int j = 0; j < m; j++)
                        work[j] += alloc[i][j];

                    safeSeq[count++] = i;
                    finish[i] = true;
                    found = true;
                }
            }
        }

        if (!found) {
            cout << "\nSystem is NOT in a safe state.\n";
            return 0;
        }
    }

    cout << "\nSystem is in a SAFE state.\nSafe Sequence: ";
    for (int i = 0; i < n; i++)
        cout << "P" <<"->"<<safeSeq[i];
    cout << endl;

    return 0;
}
