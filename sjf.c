/* A program to simulate the SJF CPU scheduling algorithm */
#include<stdio.h>
#include<string.h>
main()
{
int i=0,pno[10],bt[10],n,wt[10],temp=0,j,tt[10];
float sum,at;
printf("\n Enter the no of process ");
scanf("\n %d",&n);
printf("\n Enter the burst time of each process");
for(i=0;i<n;i++)
{
printf("\n p%d: ",i);
scanf("%d",&bt[i]);}
for(i=0;i<n-1;i++)
{
for(j=i+1;j<n;j++)
{
if(bt[i]>bt[j])
{
temp=bt[i];
bt[i]=bt[j];
bt[j]=temp;
temp=pno[i];
pno[i]=pno[j];
pno[j]=temp;
}
}
}
wt[0]=0;
for(i=1;i<n;i++)
{
wt[i]=bt[i-1]+wt[i-1];
sum=sum+wt[i];
}
printf("\n process no \t burst time\t waiting time \t turn around time\n");
for(i=0;i<n;i++)
{
tt[i]=bt[i]+wt[i];
at+=tt[i];
printf("\n p%d\t\t%d\t\t%d\t\t%d",i,bt[i],wt[i],tt[i]);
}
printf("\n\n\t Average waiting time%f\n\t Average turn around time%f", sum, at);
}
/*OUTPUT:
$ vi sjf.c
$ cc sjf.c
$ ./a.out
Enter the no of process 5
Enter the burst time of each process
p0 1
p1 5
p2 2
p3 3
p4 4
process no burst time waiting time turn around time
p0 1 0 1
p1 2 1 3
p2 3 3 6
p3 4 6 10
p4 5 10 15
Average waiting time 4.000000
Average turn around time 7.000000*/
