#include <iostream>
using namespace std;

void printArray(int A[], int n) {
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

int partition(int A[], int low, int high) {
    int pivot = A[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (A[j] <= pivot) {
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[i + 1], A[high]);
    return i + 1;
}

void quickSort(int A[], int low, int high, int n) {
    if (low < high) {
        int pi = partition(A, low, high);

        cout << "Array after partitioning with pivot index " << pi << ": ";
        printArray(A, n);

        quickSort(A, low, pi - 1, n);
        quickSort(A, pi + 1, high, n);
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int A[n];
    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    cout << "Original Array: ";
    printArray(A, n);

    quickSort(A, 0, n - 1, n);

    cout << "Sorted Array: ";
    printArray(A, n);

    return 0;
}

