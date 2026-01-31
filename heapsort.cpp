#include <iostream>
using namespace std;

int heapsize;

int left(int i) {
    return 2 * i;
}

int right(int i) {
    return 2 * i + 1;
}

void maxheapify(int A[], int i) {
    int L = left(i);
    int R = right(i);
    int largest = i;

    if (L <= heapsize && A[L] > A[largest]) {
        largest = L;
    }

    if (R <= heapsize && A[R] > A[largest]) {
        largest = R;
    }

    if (largest != i) {
        swap(A[i], A[largest]);
        maxheapify(A, largest);
    }
}

void BUILD_MAX_HEAP(int A[], int length) {
    heapsize = length;
    for (int i = length / 2; i >= 1; i--) {
        maxheapify(A, i);
    }
}

void print(int A[], int length) {
    for (int i = 1; i <= length; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

void HEAPSORT(int A[], int length) {
    BUILD_MAX_HEAP(A, length);
    cout << "After BUILD_MAX_HEAP:" << endl;
    print(A, length);

    for (int i = length; i >= 2; i--) {
        swap(A[1], A[i]);
        heapsize--;
        maxheapify(A, 1);
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int A[n + 1];
    cout << "Enter " << n << " elements:" << endl;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }


    HEAPSORT(A, n);

    cout << "Sorted Array: ";
    print(A, n);

    return 0;
}
