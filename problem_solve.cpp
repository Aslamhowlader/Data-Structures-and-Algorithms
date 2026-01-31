#include<iostream>
using namespace std;
#include<climits>
void print(int A,int n);
int merge(int A[],int p,int q,int r )
{
    int n1=q-p+1;
    int n2= r-q;
    int L[n1+1],R[n2+1];
    for(int i=1;i<n1;i++)
    {
        L[i]=A[p+i-1];

    }
    for(int j=1;j<n2;j++)
    {
        R[j]=A[q+j];
    }
     L[n1+1]= INT_MAX;
     R[n2+1] = INT_MAX;
     int i=1,j=1;
    for(int k=p;k<=r;k++)
    {
        if(L[i]<=R[j])
        {
         A[k]=L[i++];
        }
        else
        {
            A[k]=R[j++];
        }
    }
}
void print(int A[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<A[i]<< " ";
    }
    cout<<endl<<endl;

}
int merge_sort(int A[],int p,int )
int main()
{
    int A[]={9,1,8,2,7,3};
    int n=sizeof(A)/sizeof(A[0]);
}
