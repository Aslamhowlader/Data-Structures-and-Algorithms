#include<iostream>
using namespace std;

int merging(int arr1[], int arr2[], int arr3[], int n1, int n2)
{
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
        {
            arr3[k++] = arr1[i++];
        }
        else
        {
            arr3[k++] = arr2[j++];
        }
    }

    while (i < n1)
    {
        arr3[k++] = arr1[i++];
    }

    while (j < n2)
    {
        arr3[k++] = arr2[j++];
    }

    return k; // return number of merged elements
}

int main()
{
    int arr1[] = {1, 2, 3, 4, 6, 7, 8};
    int arr2[] = {9, 10, 11, 12, 13, 14, 15};
    int arr3[100];

    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    int m = merging(arr1, arr2, arr3, n1, n2); // merged size returned

    cout << "Merged Array: ";
    for (int i = 0; i < m; i++)
    {
        cout << arr3[i] << " ";
    }
    cout << endl;

    return 0;
}
