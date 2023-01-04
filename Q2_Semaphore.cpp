#include<iostream>
#include<stdlib.h>
using namespace std;
 
struct semaphore
{
    int value;
};

void wait (semaphore s)
{
    while(s.value<=0)
    s.value=s.value-1;
}

void signal(semaphore s)
{
    s.value=s.value+1;
}
int main()
{
    system("cls");
    semaphore s;
    s.value=1;
    int n,x;
    cout<<"Enter number of processes";
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        x=1;
        while(x)
        {
            wait(s);
            cout<<"Processing job "<< i<<".....!\n";
            signal(s);
            cout<<"Process "<<i<<" completed....!\n";
            x=0;
        }
    }
}