#include<iostream>
#include<stdlib.h>
using namespace std; 
int mutex=1,full=0,empty=3,x=0;
 
int main()
{
    system("cls");
    int n;
    void producer();
    void consumer();
    int wait(int);
    int signal(int);
    cout<<"\n1.Producer\n2.Consumer\n3.Exit";
    while(1)
    {
        cout<<"\nEnter your choice:";
        cin>>n;
        switch(n)
        {
            case 1:    if((mutex==1)&&(empty!=0))
                        producer();
                    else
                        cout<<"Buffer is full!!";
                    break;
            case 2:    if((mutex==1)&&(full!=0))
                        consumer();
                    else
                    cout<<"Buffer is empty!!";
                    break;
            case 3:
                    exit(0);
                    break;
        }
    }
   return 0;
}
 int wait(int s)
{
    return (--s);
}
int signal(int s)
{
    return(++s);
}
void producer()
{
    mutex=wait(mutex);
    full=signal(full);
    empty=wait(empty);
    x++;
    printf("\nProducer produces the item %d",x);
    mutex=signal(mutex);
}
void consumer()
{
    mutex=wait(mutex);
    full=wait(full);
    empty=signal(empty);
    printf("\nConsumer consumes item %d",x);
    x--;
    mutex=signal(mutex);
}