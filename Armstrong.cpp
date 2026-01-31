#include<iostream>
using namespace std;
void Aslam( int n)
{
    int temp=n;
    int sum=0;
    while(temp != 0)
    {
        int digit = temp%10;
        sum = sum + digit * digit * digit;
        temp=temp/10;
    }
    if(sum == n)
    {
        cout << n << " is an Armstrong Number" << endl;
    }
    else
    {
        cout << n << "Not is an Armstrong Number" << endl;
    }
}
int main()
{
    int n;
    cout<<"Enter the number :";
    cin>>n;

    Aslam(n);
}
