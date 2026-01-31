#include<iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of partitions and processes: ";
    cin >> n;

    int partition[n], processes[n];

    cout << "Enter the partition sizes: ";
    for (int i = 0; i < n; i++)
        cin >> partition[i];

    cout << "Enter the process sizes: ";
    for (int i = 0; i < n; i++)
        cin >> processes[i];

    bool allocation[n] = {false};        // track used partitions
    int process_allocation[n];           // store partition index for each process

    for (int i = 0; i < n; i++)
        process_allocation[i] = -1;      // initially unallocated

    // -------- FIRST FIT ALGORITHM ----------
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!allocation[j] && partition[j] >= processes[i])
            {
                process_allocation[i] = j;   // store index of partition
                allocation[j] = true;
                break;
            }
        }
    }

    int total = 0;

    // ---------- OUTPUT ----------
    for (int i = 0; i < n; i++)
    {
        cout << "Process " << i+1 << " -> ";
        if (process_allocation[i] == -1)
        {
            cout << "Not Allocated\n";
        }
        else
        {
            int p = process_allocation[i];
            cout << "Partition " << p+1 << "\n";
            total += (partition[p] - processes[i]); // internal fragmentation
        }
    }

    cout << "Total Internal Fragmentation = " << total << endl;

    return 0;
}
