#include<iostream>
using namespace std;
int binary_search(int arr[],int n,int key)
{
    int low=0,hight=n-1,Mid;
    while(low<=hight)
    {
      Mid=(low+hight)/2;
      if(arr[Mid]==key)
      {
          return Mid;
      }
      else if(arr[Mid]<key)
      {
          low=Mid+1;
      }
      else
      {
          hight=Mid-1;
      }

    }
    return -1;
}
int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    int key;
    cout<<"Enter the key : ";
    cin>>key;
    int m =binary_search(arr,n,key);
    if(m!=-1)
    {
        cout<<"binary_search index : "<<"arr["<<m<<"]="<<arr[m]<<endl;
    }
    else{
         cout<<"binary_search not index : "<<endl;
    }
    }


