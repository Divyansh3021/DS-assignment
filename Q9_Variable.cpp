#include<iostream>
#include<stdlib.h>
using namespace std;
int nb=0;
int main()
{
    system("cls");
    int msize,n;
    int mp[10];
    int tif=0,ef=0;
    int i,p=0,m=0,s=0;
    int t=0;
    cout<<"Enter the total memory available (in Bytes) : ";
    cin>>msize;
    cout<<"Enter the number of processes: ";
    cin>>n;
    for(i=0;i<n;i++){
        cout<<"Enter the memory required for process "<<i+1<<"(in Bytes): ";
        cin>>mp[i];
        s=s+mp[i];
        if(s<msize){nb++;}
    }
    cout<<"Number of blocks which can be accomodated:"<<nb;
    cout<<"\n\nPROCESS\t  MEMORY REQUIRED\tALLOCATED";
    for(i=0;i<n && p<nb;i++){
        cout<<"\n\t"<<i+1<<"\t"<<mp[i];
        m+=mp[i];
        if(m>msize){cout<<"\t\tNO";}
        else{
            cout<<"\t\tYES";
            t=t+mp[i];
            p++;
        }
    }
    if(i<n){cout<<"\nMEMORY IS FULL, REMAINING PROCESS CAN'T BE ACCOMODATED\n";}
    ef=msize-t;
    cout<<"\nTOTAL EXTERNAL FRAGMENTATION is "<<ef;
    return 0;
}
