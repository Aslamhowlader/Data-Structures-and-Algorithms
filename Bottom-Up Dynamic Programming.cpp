#include<iostream>
#include<climits>
using namespace std;
void cuting(int p[],int n,int r[],int s[])
{
    r[0]=0;
    for(int j=1;j<=n;j++)
    {
        int q= INT_MIN;
        for(int i=1;i<=j;i++)
        {
            if(q<p[i]+r[j-i])
            {
                q=p[i]+r[j-i];
                s[j]=i;
            }
        }
        r[j]=q;
    }
}
void printCuts(int s[],int n)
{
    while(n>0)
    {
        cout<<s[n];
        n=n-s[n];
        if(n>0)cout<<"+";
    }

}
int main()
{
    int p[]={1,5,8,9,10,17,17,20,24,30};
    int n=10;
    int r[11];
    int s[11];

    cuting(p,n,r,s);
     cout<<"Rod length | max Revenue | optimal Cuts\n";
     cout<<".........................................\n";
     for(int i=1;i<=n;i++)
     {
         cout<<"r"<<i<<"          | "<<r[i]<<"          |";
       printCuts(s,i);
       cout<<endl;
     }
     cout<<"\nMaximum revenue for rod length "<<n<<" = "<<r[n]<<endl;

     return 0;
}
