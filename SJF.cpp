#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int p[n], A[n], B[n], C[n], T[n], W[n], R[n];
    bool completed[n] = {false};
    int total_T = 0, total_W = 0, total_R = 0;

    for(int i=0; i<n; i++) {
        cout << "Enter arrival and burst time for P" << i+1 << ": ";
        cin >> A[i] >> B[i];
        p[i] = i+1;
    }

    int time = 0, completed_count = 0;

    while(completed_count < n) {
        int idx = -1;
        int minBurst = 1e9;

        // Find the process with shortest burst time among arrived and not completed
        for(int i=0; i<n; i++) {
            if(!completed[i] && A[i] <= time && B[i] < minBurst) {
                minBurst = B[i];
                idx = i;
            }
        }

        if(idx == -1) {
            time++;  // No process has arrived yet
            continue;
        }

        int start = time;
        R[idx] = start - A[idx];      // Response time
        C[idx] = start + B[idx];      // Completion time
        T[idx] = C[idx] - A[idx];     // Turnaround time
        W[idx] = T[idx] - B[idx];     // Waiting time

        total_T += T[idx];
        total_W += W[idx];
        total_R += R[idx];

        time = C[idx];
        completed[idx] = true;
        completed_count++;
    }

    // ----- Output -----
    cout << "\nProcess | Arrival | Burst | Completion | Turnaround | Waiting | Response\n";
    cout << "-----------------------------------------------------------------------\n";
    for(int i=0; i<n; i++) {
        cout << "P" << p[i] << "\t|\t" << A[i] << "\t|\t" << B[i]
             << "\t|\t" << C[i] << "\t|\t" << T[i] << "\t|\t" << W[i]
             << "\t|\t" << R[i] << endl;
    }

    cout << "\nAverage Waiting Time: " << (float)total_W/n << endl;
    cout << "Average Turnaround Time: " << (float)total_T/n << endl;
    cout << "Average Response Time: " << (float)total_R/n << endl;

    return 0;
}

