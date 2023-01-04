#include<iostream>
#include<stdlib.h>
using namespace std;

int main()
{
    system("cls");
    int p,r,a,k=0;
    cout<<"Enter the number of processes:";
    cin>>p;
    cout<<"Enter the number of resources for each process: ";
    cin>>r;
    cout<<"\n";
    int request[p][r], allocation[p][r];
    int available[r], work[r],finish[p], safe[p];
    cout<<"Enter the elements of allocation matrix:\n";
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<r;j++)
        {
            cin>>a;
            allocation[i][j]=a;
        }
    }
    cout<<"\n";
    cout<<"enter the elements of request matrix:\n";
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<r;j++)
        {
            cin>>a;
            request[i][j]=a;
        }
    }
    cout<<"\n";
    cout<<"Enter the number of available resources:\n";
    for(int i=0;i<r;i++)
    {
        cin>>a;
        available[i]=a;
        work[i]=available[i];
    }
    cout<<"\n";
    cout<<"Process\tAllocation\t Request\n";
    for(int i=0;i<p;i++)
    {
    cout<<"P\t"<<i+1;
    finish[i]=0;
    for(int j=0;j<r;j++)
    {
        cout<<allocation[i][j];
    }
    cout<<"\t\t";
    for(int j=0;j<r;j++)
    {
        cout<<request[i][j];
    }
    cout<<"\n";
    }
    cout<<"\n";
    for(int i=0;i<p;i++)
    {
        if(finish[i]==0){
            for(int j=0;j<r;j++){
                if(request[i][j]<=work[j]){
                    finish[i]=1;
                }
                else{
                    finish[i]=0;
                    break;
                }
            }
        }
        if(finish[i]==1){
            for(int j=0;j<r;j++)
            {
                work[j]=work[j]+allocation[i][j];

            }
            safe[k]=i;
            k++;
            i=0;
        }
    }
    for(int i=0;i<p;i++)
    {
        if(finish[i]==0)
        {
            cout<<"The state generated is unsafe.";
            return 0;
        }
    }
    cout<<"The state generated is safe.\n The safe sequence is: ";
    for(int i=0;i<p;i++)
    {
        cout<<"P "<<safe[i]+1;
    }
    cout<<"\n";
    return 0;
}