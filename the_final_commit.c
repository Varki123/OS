#include<stdio.h>
#include<dos.h>
int main()
{
    int gifts[20], p[20], wt[20], tat[20], i, j, n=10, total=0, pos, temp, avg_wt, avg_tat;
	/* gifts[] stores the number of gifts bought by each student
	   p[]	stores the next process
	   wt[] waiting time
	   tat[] turnaround time
	   n is the number of students(10=given)
	   avg_wt is the aveage waiting time
	   avg_tat is the average tutn around time */
	
	printf("\n\t\t---> THE ARCHIES <---");
 	printf("\n\t      ________________________");
 	printf("\n\n(TEN Students (a,b,c,d,e,f,g,h,i,j) enter 'The Archies' to buy gifts for an event)");
	printf("\n\n\nThe no of gifts bought by each child:-");
	printf("\n---------------------------------------");
    for(i=0;i<n;i++)
    {
    	printf("\n\nNo. of gifts bought by child %d: ",i+1);
    	scanf("%d",&gifts[i]);
    	p[i]=i+1;
    	    	
	}
	
	printf("\n");
	
  for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(gifts[j]>gifts[pos])
                pos=j;
        }
 
        temp=gifts[i];
        gifts[i]=gifts[pos];
        gifts[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }

	
	printf("PLEASE WAIT for a few seconds!!!");
	sleep(3);
    
   	wt[0]=0;    //waiting time for first process is zero
	//calculate waiting time
 	for(i=1;i<n;i++)
 	{
    	wt[i]=0;
     	for(j=0;j<i;j++)
        	wt[i]+=gifts[j];
			total+=wt[i];
	}

	avg_wt=total/n;      //average waiting time
 	total=0;

	printf("\nThe order of billing \tNo. of gifts  \tWaiting Time \tTurnaround Time");
	for(i=0;i<n;i++)
	{
    	tat[i]=gifts[i]+wt[i];     //calculate turnaround time
    	total+=tat[i];
		printf("\n     Student %d \t \t    %d \t \t     %d \t \t     %d",p[i],gifts[i],wt[i],tat[i]);
 	}

 avg_tat=total/n;     //average turnaround time
 printf("\n\nAverage Waiting Time=%d",avg_wt);
 printf("\nAverage Turnaround Time=%d\n",avg_tat);

}
