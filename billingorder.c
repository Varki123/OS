#include<stdio.h>

int main()
{
    int gifts[20], p[20], wt[20], tat[20], pr[20], i, j, n, total=0, pos, temp, avg_wt, avg_tat, a[20],t;
    printf("Enter the Total Number of Children entering the shop: ");
    scanf("%d",&n);

 	printf("\nEnter the no of gifts bought by each child");
    for(i=0;i<n;i++)
    {
    	printf("\nNo. of gifts: ");
    	scanf("%d",&gifts[i]);
    	p[i]=i+1;
	}

  for(i=0;i<n;i++)
  {
        for(j=i;j<n;j++)
        {
        	if(gifts[i]<gifts[j])
        	{
				temp=gifts[i];
        		gifts[i]=gifts[j];
        		gifts[j]=temp;
 			}
    }

 		printf("%d\n", gifts[i]);


	}

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

 printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
 for(i=0;i<n;i++)
 {
     tat[i]=gifts[i]+wt[i];     //calculate turnaround time
     total+=tat[i];
     printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d",p[i],gifts[i],wt[i],tat[i]);
 }

 avg_tat=total/n;     //average turnaround time
 printf("\n\nAverage Waiting Time=%d",avg_wt);
 printf("\nAverage Turnaround Time=%d\n",avg_tat);

}
