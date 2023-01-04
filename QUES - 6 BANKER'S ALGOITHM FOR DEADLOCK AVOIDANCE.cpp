// Banker's algorithm for deadlock avoidance .

#include<iostream>
using namespace std ;

int maxi[10][10],allocation[10][10],need[10][10],avail[10] ;
int np , nr ;

void readmatrix(int matrix[10][10])
{
	for(int i=0 ; i<np ; i++)
	{
		for(int j=0 ; j<nr ; j++)
		{
			cin>> matrix[i][j] ;
		}
	}
}

void display_matrix(int matrix[10][10])
{
	for(int i=0 ; i<np ; i++)
	{
		cout<<"\nP" << i << " " ;
		
		for(int j=0 ; j<nr ; j++)
		{
			cout<< matrix[i][j] << " " ; 
		}
	}
}

void calculate_need()
{
	for(int i=0 ; i<np ; i++)
	{
		for(int j=0 ; j<nr ; j++)
		{
			need[i][j] = maxi[i][j]-allocation[i][j] ;
		}
	}
}

void banker()
{
	int flag , k=0 , finish[10] , safe_seq[10] ; 
	
	for(int i=0 ; i<np ; i++)
	{
		finish[i] = 0 ; 	// Declare as all processes are incomplete ...
	}
	
	for(int i=0 ; i<np ; i++)
	{
		flag = 0 ;
		
		if(finish[i]==0)	// Execute incomplete processes .....
		{
			for(int j=0 ; j<nr ; j++)	// check a need of each process ....
			{
				if(need[i][j]>avail[j])
				{
					flag = 1 ;	  // Break a loop as need is greater than avail and go to next process ..... 	
					break ;
				}			
			}			
		}
		
		if(flag==0)		// Need is lesser than avail so complete process ....
		{
			finish[i] = 1 ;
			safe_seq[k] = i ;
			k++ ;
			
			// Add allocated resources of finished process in available resources .....
			
			for(int j=0 ; j<nr ; j++)
			{
				avail[j] = avail[j]+allocation[i][j] ;
			}
			
			// start checking from first process again ....	
			i = -1 ;				 
		}
	}
	
	flag = 0 ;	   // check if all processes are completed .....
	
	for(int i=0 ; i<np ; i++)
	{
		if(finish[i]==0)
		{
			cout<<"\nThe system is in deadlock ......!" ;
			flag = 1 ;
			break ;
		}
	}
	
	if(flag==0)
	{
		cout<<"\nThe system is in safe state ! " ;
		cout<<"\nSafe sequence is ===> " ;
		
		for(int i=0 ; i<np ; i++)
		{
			cout<<"P" << safe_seq[i] << " " ;
		}
	}
}


int main()
{
	// reading the data ...
	
	cout<<"\nEnter the number of processes : " ;
	cin>> np ;
	
	cout<<"\nEnter the number of resources : " ;	
	cin>> nr ;
	
	cout<<"\nEnter the initial allocation matrix : \n" ;	
	readmatrix(allocation) ;
	
	cout<<"\nEnter the max requirement matrix : \n" ;	
	readmatrix(maxi) ;

	cout<<"\nEnter the available resources : " ;
	
	for(int i=0 ; i<nr ; i++)
	{
		cin>> avail[i] ;	
	}	
	
	// displaying the data .......
	
	cout<<"\nEntered data is ......\n" ;
	
	cout<<"\nInitial Allocation : \n" ;
	display_matrix(allocation) ;
	
	cout<<"\n\nMaximum Requirements : \n" ;
	display_matrix(maxi) ;
	
	cout<<"\n\nAvailable Resources : \n" ;
	
	for(int i=0 ; i<nr ; i++)
	{
		cout<< avail[i] << " " ;
	}
	
	// Calculate and display need ......
	calculate_need() ;
	
	cout<<"\n\nNeed is ......\n" ;
	display_matrix(need) ;
	
	// Execute the processes using bankers algorithm ......
	banker() ;
	
	cout<<"\n" ;
	
	return 0 ;

}






