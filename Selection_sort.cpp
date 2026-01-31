#include <iostream>
using namespace std;

void printArray(int A[], int n) {
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

void selectionSort(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (A[j] < A[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            swap(A[i], A[minIndex]);
        }

        cout << "Array after pass " << i + 1 << ": ";
        printArray(A, n);
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


    selectionSort(A, n);

    cout << "Sorted Array: ";
    printArray(A, n);

    return 0;
}

