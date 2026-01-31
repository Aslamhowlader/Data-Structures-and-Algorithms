#include <iostream>
using namespace std;

int heap_size;

int LEFT(int i) {
    return 2 * i;
}

int RIGHT(int i) {
    return 2 * i + 1;
}

void print(int A[], int length) {
    for (int i = 1; i <= length; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

void MAX_HEAPIFY(int A[], int i) {
    int l = LEFT(i);
    int r = RIGHT(i);
    int largest;

    if (l <= heap_size && A[l] > A[i])
        largest = l;
    else
        largest = i;

    if (r <= heap_size && A[r] > A[largest])
        largest = r;

    if (largest != i) {
        swap(A[i], A[largest]);
        MAX_HEAPIFY(A, largest);
    }
}

void BUILD_MAX_HEAP(int A[], int length) {
    heap_size = length;
    for (int i = length / 2; i >= 1; i--) {
        MAX_HEAPIFY(A, i);
    }
}

void HEAPSORT(int A[], int length) {
    BUILD_MAX_HEAP(A, length);
    cout << "After BUILD_MAX_HEAP:" << endl;
    print(A, length);

    for (int i = length; i >= 2; i--) {
        swap(A[1], A[i]);
        heap_size--;

        MAX_HEAPIFY(A, 1);

    }
}

int main() {
    int A[] = {0, 4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    int length = sizeof(A) / sizeof(A[0])-1;

    cout << "Original array:" << endl;
    print(A, length);

    HEAPSORT(A, length);

    cout << "Sorted array:" << endl;
    print(A, length);

    return 0;
}
