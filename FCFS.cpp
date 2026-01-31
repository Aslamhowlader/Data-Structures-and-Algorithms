#include<iostream>
using  namespace std;
int main()
{
    int n;
    cout<<"Enter number of processes : ";
    cin>>n;
    int p[n],A[n],B[n],C[n],T[n],W[n],R[n];
    int total_T=0,total_W=0,total_R=0;

    for(int i=0; i<n;i++)
    {
        cout<<"Enter arrival and burst time for p "<<i+1<<":";
        cin>>A[i]>>B[i];
        p[i]=i+1;
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(A[j]>A[j+1])
            {
                swap(A[j],A[j+1]);
                swap(B[j], B[j+1]);
                swap(p[j],p[j+1]);
            }
        }
    }
    int time=0;
    for(int i=0; i<n; i++)
    {
        if(time<A[i])
        {
            time=A[i];
        }
        time+=B[i];
        C[i]=time;
        T[i]=C[i]-A[i];
        W[i]=T[i]-B[i];
        R[i]=time-A[i];

    }
        cout << "\nProcess | Arrival | Burst | Completion | Turnaround | Waiting | Response\n";
    cout << "-----------------------------------------------------------------------\n";

    for(int i=0;i<n;i++)
    {
        cout<<"P"<<p[i]<<"\t|"<<A[i]<<"\t|"<<B[i]<<"\t|"<<C[i]<<"\t|"<<T[i]<<" \t|"<<W[i]<<"\t|"<<R[i]<<endl;
          total_T=T[i];
          total_W=W[i];
          total_R=R[i];
    }
    cout << "\nAverage Waiting Time: " << total_W/n << endl;
    cout << "Average Turnaround Time: " << total_T/n << endl;
    cout << "Average Response Time: " << total_R/n << endl;

}
