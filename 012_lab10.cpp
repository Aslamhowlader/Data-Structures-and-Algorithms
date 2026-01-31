#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void allocateMemory(const string &strategy, vector<int> partitions, vector<int> processes) {
    int n = partitions.size();
    int m = processes.size();
    vector<int> allocation(m, -1);
    int internalFrag = 0;

    if (strategy == "First Fit") {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (processes[i] <= partitions[j]) {
                    allocation[i] = j;
                    internalFrag += (partitions[j] - processes[i]);
                    partitions[j] = -1;
                }
            }
        }
    } else if (strategy == "Best Fit") {
        for (int i = 0; i < m; i++) {
            int bestIndex = -1;
            int minDiff = 1e9;
            for (int j = 0; j < n; j++) {
                if (processes[i] <= partitions[j] && (partitions[j] - processes[i]) < minDiff) {
                    minDiff = partitions[j] - processes[i];
                    bestIndex = j;
                }
            }
            if (bestIndex != -1) {
                allocation[i] = bestIndex;
                internalFrag += (partitions[bestIndex] - processes[i]);
                partitions[bestIndex] = -1;
            }
        }
    } else if (strategy == "Worst Fit") {
        for (int i = 0; i < m; i++) {
            int worstIndex = -1;
            int maxDiff = -1;
            for (int j = 0; j < n; j++) {
                if (processes[i] <= partitions[j] && (partitions[j] - processes[i]) > maxDiff) {
                    maxDiff = partitions[j] - processes[i];
                    worstIndex = j;
                }
            }
            if (worstIndex != -1) {
                allocation[i] = worstIndex;
                internalFrag += (partitions[worstIndex] - processes[i]);
                partitions[worstIndex] = -1;
            }
        }
    }


    cout << strategy << "\nAllocation: ";
    for (int i = 0; i < m; i++) {
        if (allocation[i] != -1)
            cout << "P" << i + 1 << "->" << allocation[i] + 1 << " ";
        else
            cout << "P" << i + 1 << "->Not Allocated ";
    }
    cout << "\nTotal Internal Fragmentation: " << internalFrag << "\n\n";
}

int main() {
    int n, m;
    cin >> n;
    vector<int> partition_sizes(n);
    for (int i = 0; i < n; i++) cin >> partition_sizes[i];

    cin >> m;
    vector<int> process_sizes(m);
    for (int i = 0; i < m; i++) cin >> process_sizes[i];

    allocateMemory("First Fit", partition_sizes, process_sizes);
    allocateMemory("Best Fit", partition_sizes, process_sizes);
    allocateMemory("Worst Fit", partition_sizes, process_sizes);

    return 0;
}

