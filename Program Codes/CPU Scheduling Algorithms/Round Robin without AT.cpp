#include<iostream>
using namespace std;
typedef struct Queue
{
int val[200];
int front;
int rear;
}queue;
queue createQueue()
{
queue q;
q.front = 0;
q.rear = 0;
return q;
}
int isEmpty(queue q)
{
if(q.front == q.rear)
return 1;
return 0;
}
int isFull(queue q)
{
if((q.rear+1)%200 == q.front)
return 1;
return 0;
}
int insert(queue *q, int data)
{
if(isFull(*q))
return 0;
q->rear = (q->rear + 1)%200;
q->val[q->rear] = data;
return 1;
}
int del(queue *q, int *data)
{
if(isEmpty(*q))
return 0;
q->front = (q->front + 1)%200;
*data = q->val[q->front];
return 1;
}
int main()
{
int *BT,*CT,*TAT,*WT,*PID,*AT,*tempBT,*visited,n,tq;
float avgTAT = 0.0,avgWT = 0.0;
cout<<"Round Robin First Algorithm.";
cout<<"\n Enter the number of processes: ";
cin>>n;
BT = new int[n];
CT = new int[n];
AT = new int[n];
TAT = new int[n];
WT = new int[n];
PID = new int[n];
tempBT = new int[n];
visited = new int[n];
cout<<"\n Enter time quantum: ";
cin>>tq;
for(int i=0;i<n;i++)
{
cout<<"\nEnter Burst Time of Process "<<i+1<<": ";
cin>>BT[i];
tempBT[i] = BT[i];
AT[i] = i;
PID[i] = i+1;
visited[i] = 0;
}
int comp = 0,p;
queue q = createQueue();
insert(&q, 0);
visited[0]=1;
do
{
del(&q,&p);
if(BT[p] > tq)
{
comp = comp + tq;
BT[p] = BT[p] - tq;
}
else
{
comp = comp + BT[p];
BT[p] = 0;
CT[p] = comp;
}
for(int i = 0; i<n ; i++)
{
if((AT[i]<=comp)&&(!visited[i]))
{
insert(&q, i);
visited[i]=1;
}
}
if(BT[p])
insert(&q, p);
}while(!isEmpty(q));
cout<<"\n P.NO\t AT\t BT\t CT\t TAT\t WT";
for(int i=0;i<n;i++)
{
TAT[i] = CT[i] - AT[i];
WT[i] = TAT[i] - tempBT[i];
avgTAT = avgTAT + TAT[i];
avgWT = avgWT + WT[i];

cout<<"\n "<<PID[i]<<"\t "<<AT[i]<<"\t "<<tempBT[i]<<"\t "<<CT[i]<<"\t"<<TAT[i]<<"\t "<<WT[i];
}
avgTAT = avgTAT/float(n);
avgWT = avgWT/float(n);
cout<<"\n\n Average TAT: "<<avgTAT;
cout<<"\n Average WT: "<<avgWT<<"\n";
return 0;
}