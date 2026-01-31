#include<iostream>
using namespace std;
void  insertionfront(int arr[],int &n,int value)
{
    for(int i=n; i>0;i--)
    {
        arr[i]=arr[i-1];
    }
    arr[0]=value;
    n++;

}
void insertionmid(int arr[],int &n,int pos,int value )
{
    if(pos<0 || pos>n)
    {
        cout<<"invalet postion";
         return;
    }
    for(int i=n;i>pos;i--)
    {
      arr[i]=arr[i-1];
    }
    arr[pos]=value;
    n++;
}
void insertionend(int arr[],int &n,int value)
{
    arr[n]=value;
    n++;
}
void Treavsal(int arr[],int &n)
{
    for(int i=0;i<n;i++)
    {
       cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void deletionfront(int arr[],int &n)
{
void deletionmid(int arr[],int &n,int pos)
{
    if(n<=0)
    {
        cout << "Array is empty. Nothing to delete." << endl;
        return;
    }
    for(int i=0;i<n;i++)
    {
        arr[i]=arr[i+1];

    }
 n--;
}
    if(pos<0 || pos>n)
    {
        cout << "Array is empty. Nothing to delete." << endl;
        return;
    }
    for(int i=pos;i<n;i++)
    {
        arr[i]=arr[i+1];
    }
    n--;
}
void deletionend(int arr[],int &n)
{
    if(n<=0)
    {
       cout << "Array is empty. Nothing to delete." << endl;
        return;
    }
    n--;

}
int  minm(int arr[],int &n)
{
   int min=arr[0];
    for(int i=1;i<n;i++)
    {

        if(arr[i]<min)
        {
           min=arr[i];
        }
    }
  return min;
}
int max(int arr[],int &n)
{
    int mxaum=arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]>mxaum)
        {
            mxaum=arr[i];
        }
    }
    return mxaum;
}
int Liner(int arr[],int &n,int value)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==value)
        {
            return i;
        }
    }
    return -1;
}
int binary(int arr[], int &n, int value)
{
    int high = n - 1, low = 0;

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(arr[mid] == value)
        {
            return mid;
        }
        else if(arr[mid] < value)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

void bubble(int arr[],int n)
{
    int temp;
    for(int i = 0; i < n-1; i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
             temp=arr[j];
              arr[j]=arr[j+1];
              arr[j+1]=temp;
            }
        }
    }
}
void insertion(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        int temp=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>temp)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}
void selection(int arr[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        int min = i;
        for(int j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }
        }
        if(min != i)
        {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}
int main(){
int arr[]={8,7,4,9,25,6,2,3,7,87};
int n=sizeof(arr)/sizeof(arr[0]);
 Treavsal(arr,n);
 cout<<"insertion front :  ";
 insertionfront(arr,n,100);
  Treavsal(arr,n);
  cout<<"insertion Mid : ";
  insertionmid(arr,n,6,400);
  Treavsal(arr,n);
  cout<<"insertion end : ";
  insertionend(arr,n,500);
  Treavsal(arr,n);
  cout<<"Deletion : ";
  deletionfront(arr,n);
  Treavsal(arr,n);
cout<<"Deletion Mid : ";
  deletionmid(arr,n,4);
  Treavsal(arr,n);
  deletionend(arr,n);
  Treavsal(arr,n);
  int m = minm(arr,n);
  cout<<"min : "<<m<<endl;
  int b = max(arr,n);
  cout<<"max : "<<b<<endl;
   int w=Liner(arr,n,7);
  if(w!=-1)
  {
     cout << "Element found at index " <<"arr["<<w<<"]="<<arr[w] << endl;
  }
  else
  {
      cout << "Element not found!" << endl;
  }
  int res = binary(arr, n, 5);

if(res != -1)
{
    cout << "Element found at index " << res << ": arr[" << res << "] = " << arr[res] << endl;
}
else
{
    cout << "Element not found!" << endl;
}
cout<<"Bubble sort : ";
 bubble(arr,n);
Treavsal(arr,n);
cout<<"insertion sort : ";
insertion(arr,n);
Treavsal(arr,n);
cout<<" Selection sort : ";
selection(arr,n);
Treavsal(arr,n);

}
