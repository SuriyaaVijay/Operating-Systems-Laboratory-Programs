#include<bits/stdc++.h>
using namespace std;
void sortall(int *BT, int *PID, int *AT, int *CT, int *TAT, int *WT, int *tempBT, int n) {
for(int i=0;i<n;i++)
{
int pos=i;
for(int j=i+1;j<n;j++)
{
if(BT[j]<BT[pos])
pos=j;
}
int temp=BT[i];
BT[i]=BT[pos];
BT[pos]=temp;
temp=PID[i];
PID[i]=PID[pos];
PID[pos]=temp;
temp=AT[i];
AT[i]=AT[pos];
AT[pos]=temp;
temp=TAT[i];
TAT[i]=TAT[pos];
TAT[pos]=temp;
temp=CT[i];
CT[i]=CT[pos];
CT[pos]=temp;
temp=WT[i];
WT[i]=WT[pos];
WT[pos]=temp;
temp=tempBT[i];
tempBT[i]=tempBT[pos];
tempBT[pos]=temp;
}
}
int main()
{
int *BT,*CT,*TAT,*WT,*PID,*AT,*tempBT,n;
float avgTAT = 0.0,avgWT = 0.0;
cout<<"Shortest Job First Algorithm.";
cout<<"\n Enter the number of processes: ";
cin>>n;
BT = new int[n];
CT = new int[n];
AT = new int[n];
TAT = new int[n];
WT = new int[n];
PID = new int[n];
tempBT = new int[n];
for(int i=0;i<n;i++)
{
cout<<"\nEnter Burst Time of Process "<<i+1<<": ";
cin>>BT[i];
tempBT[i] = BT[i];
cout<<"\n"<<BT[i];
AT[i] = i;
PID[i] = i+1;
}
int comp = 0;
for(int i = 0;i<n;i++)
{
CT[0] = comp + tempBT[0];
cout<<"\nCT : "<<CT[0];
TAT[0] = CT[0] - AT[0];
cout<<" TAT : "<<TAT[0];
WT[0] = TAT[0] - tempBT[0];
cout<<" WT : "<<WT[0];
BT[0] = INT_MAX;
cout<<" BT : "<<tempBT[0];
comp = CT[0];
cout<<" comp : "<<comp;
cout<<" AT : "<<AT[0];
if(comp<n)
sortall(BT,PID,AT,CT,TAT,WT,tempBT,comp);
else
sortall(BT,PID,AT,CT,TAT,WT,tempBT,n);
}
cout<<"\n P.NO\t AT\t BT\t CT\t TAT\t WT";
for(int i=0;i<n;i++)
{
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