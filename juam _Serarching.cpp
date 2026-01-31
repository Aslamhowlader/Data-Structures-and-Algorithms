#include<iostream>
#include<cmath>
using namespace std;

int jump(int arr[], int n, int key)
{
    int step = sqrt(n);
    int prev = 0;


    while (arr[min(step, n)-1] < key) {
        prev = step;
        step += sqrt(n);
        if (prev >= n)
            return -1;
    }


    for (int i = prev; i < min(step, n); i++) {
        if (arr[i] == key)
            return i;
    }

    return -1;
}

int main()
{
    int arr[] = {19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;

    cout << "Enter the element: ";
    cin >> key;

    int index = jump(arr, n, key);

    if (index != -1) {
        cout << "Jump index: arr[" << index << "] = " << arr[index] << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}
