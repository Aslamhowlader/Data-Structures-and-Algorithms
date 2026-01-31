#include<iostream>
using namespace std;

void convert(int n, int bin[]) {
    int i = 0;

    if(n == 0) {
        cout << "0" << endl;
        return;
    }

    for(; n > 0; i++) {
        bin[i] = n % 2;
        n = n / 2;
    }

    cout << "Binary: ";
    for(int j = i - 1; j >= 0; j--) {
        cout << bin[j];
    }
    cout << endl;
}

int main() {
    int bin[100], n;
    cout << "Enter the number: ";
    cin >> n;

    convert(n, bin);
    return 0;
}
