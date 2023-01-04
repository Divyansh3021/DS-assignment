#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
    system("cls");
    int msize,bsize,nb,ef,n;
    int mp[10],tif=0;
    int i,p=0;
    cout<<"Enter the total memory available (in Bytes) : ";
    cin>>msize;
    cout<<"Enter the block size (in Bytes): ";
    cin>>bsize;
    nb=msize/bsize;
    ef=msize-(nb*bsize);
    cout<<"Enter the number of processes: ";
    cin>>n;
    for(i=0;i<n;i++)
    {
        cout<<"Enter the memory required for process"<<i+1<<" (in Bytes): ";
        cin>>mp[i];
    }
    cout<<"Number of blocks available in memory: "<<nb;
    cout<<"\n\nPROCESS\t  MEMORY REQUIRED\tALLOCATED\tINTERNAL FRAGMENTATION\n";
    for(i=0;i<n && p<nb;i++){
        cout<<"\n\t"<<i+1<<"\t"<<mp[i];
        if(mp[i]>bsize){cout<<"\t\tNO\t\t";}
        else{
            cout<<"\t\tYES\t\t"<<bsize-mp[i];
            tif=tif+bsize-mp[i];
            p++;
        }
    }
    if(i<n){cout<<"\nMEMORY IS FULL, REMAINING PROCESS CAN'T BE ACCOMODATED\n";}
    cout<<"\nTOTAL INTERNAL FRAGMENTATION is "<<tif;
    cout<<"\nTOTAL EXTERNAL FRAGMENTATION is "<<ef;
    return 0;}