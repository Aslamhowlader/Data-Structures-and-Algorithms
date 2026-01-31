#include <iostream>
#include <climits>
using namespace std;

void printArray(int A[], int n) {
    for (int i = 1; i <= n; i++)
        cout << A[i] << "  ";
    cout << endl << endl;
}

void merge(int A[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1 + 1], R[n2 + 1];


    for (int i = 1; i <= n1; i++)
        L[i] = A[p + i - 1];
    for (int j = 1; j <= n2; j++)
        R[j] = A[q + j];

    L[n1 + 1] = INT_MAX;
    R[n2 + 1] = INT_MAX;

    int i = 1, j = 1;
    for (int k = p; k <= r; k++) {
        if (L[i] <= R[j])
            A[k] = L[i++];
        else
            A[k] = R[j++];
    }

    cout << "After merging indices " << p << " to " << r << ": ";
    printArray(A, r);
}

void mergeSort(int A[], int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        mergeSort(A, p, q);
        mergeSort(A, q + 1, r);
        merge(A, p, q, r);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int A[n + 1];
    cout << "Enter " << n << " elements: ";
    for (int i = 1; i <= n; i++)
        cin >> A[i];

    cout << "\nInitial array: ";
    printArray(A, n);

    mergeSort(A, 1, n);

    cout << "Sorted array: ";
    printArray(A, n);

    return 0;
}
