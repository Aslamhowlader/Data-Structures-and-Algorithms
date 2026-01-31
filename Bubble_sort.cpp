#include<iostream>
using namespace  std;
int bubble(int arr[],int n)
{
    int temp;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp =arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
void insertion(int arr[],int n)
{
    for(int i=1;i<n;i++)
    {
        int temp =arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>temp)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}
void print(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int arr[]={9,1,8,2,7,3,6,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    print(arr,n);
    bubble(arr,n);
    cout<<" Bubble Soted Array : ";
     print(arr,n);
     insertion(arr,n);
 cout<<" insertoin Soted Array : ";
     print(arr,n);

}
