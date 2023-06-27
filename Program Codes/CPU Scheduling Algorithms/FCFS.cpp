//FCFS 
#include<iostream>
using namespace std;
int main()
{
int *BT,*CT,*TAT,*WT,n;
float avgTAT = 0.0,avgWT = 0.0;
cout<<"First Come First Serve Algorithm.";
cout<<"\n Enter the number of processes: ";
cin>>n;
BT = new int[n+1];
CT = new int[n+1];
TAT = new int[n+1];
WT = new int[n+1];
BT[0] = 0;
TAT[0] = 0;
CT[0] = 0;
WT[0] = 0;
for(int i=1;i<=n;i++)
{
cout<<"\nEnter Burst Time of Process "<<i<<": ";
cin>>BT[i];
CT[i] = CT[i-1] + BT[i];
TAT[i] = CT[i] - (i-1);
WT[i] = TAT[i] - BT[i];
avgTAT = avgTAT + TAT[i];
avgWT = avgWT + WT[i];
}
avgTAT = avgTAT/float(n);
avgWT = avgWT/float(n);
cout<<"\n P.NO\t AT\t BT\t CT\t TAT\t WT";
for(int i = 1;i<=n;i++)
cout<<"\n "<<i<<"\t "<<i-1<<"\t "<<BT[i]<<"\t "<<CT[i]<<"\t "<<TAT[i]<<"\t"<<WT[i];
cout<<"\n\n Average TAT: "<<avgTAT;
cout<<"\n Average WT: "<<avgWT<<"\n";
return 0;
}