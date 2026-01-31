#include<iostream>
using namespace std;
int Serarching(int arr[],int n,int key)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==key)
        {
            return i;
        }
    }
    return -1;

}
int main()
{
    int arr[]={9,7,5,3,2,4,12,4,5,39};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key;
    cout<<"Enter the key : ";
    cin>>key;
    int m =Serarching(arr,n,key);
    if(m!=-1){
    cout<<"Serarching value index :"<<"arr["<<m<<"]="<<arr[m]<<endl;
    }
    else
    {
        cout<<"Serarching not value"<<endl;
    }
}
