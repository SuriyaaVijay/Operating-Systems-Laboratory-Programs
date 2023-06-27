#include<bits/stdc++.h>
using namespace std;
void scan(vector<int>, int, vector<int>, int , char, int);
int main()
{
int n, head, seek_time, seek_count = 0, disk_size;
vector<int> seek_sequence, reqarr;
char dir;
cout<<"\n Scan Algorithm.";
cout<<"\nEnter the number of locations: ";
cin>>n;
for(int i=0 ; i<n ;i++)
{
int temp;
cout<<"\nEnter location "<<i+1<<": ";
cin>>temp;
reqarr.push_back(temp);
}
cout<<"\nEnter Disk Head Pointer: ";
cin>>head;
cout<<"\n Enter direction (L or R): ";
cin>>dir;
cout<<"\n Enter Disk size: ";
cin>>disk_size;
scan(reqarr, head, seek_sequence, n, dir, disk_size);
return 0;
}
void scan(vector<int> reqarr, int head, vector<int> seek_sequence, int n, char dir, int
disk_size)
{
vector<int> left, right;
for(int i=0 ; i<n ; i++)
{
if(reqarr[i] < head)
left.push_back(reqarr[i]);
else if(reqarr[i] > head)
right.push_back(reqarr[i]);
}
int distance = 0, seek_count = 0, curr_pos = head;
sort(right.begin(), right.end());
sort(left.begin(), left.end(), greater<int>());
if(dir == 'R')
{
for (int i = 0; i < right.size(); i++)
{
distance = abs(curr_pos - right[i]);
curr_pos = right[i];
seek_sequence.push_back(curr_pos);
seek_count = seek_count + distance;
}
distance = abs(curr_pos - disk_size);
curr_pos = disk_size;
seek_sequence.push_back(curr_pos);
seek_count = seek_count + distance;
for(int i=0 ; i<left.size() ; i++)
{
distance = abs(curr_pos - left[i]);
curr_pos = left[i];
seek_sequence.push_back(curr_pos);
seek_count = seek_count + distance;
}
}
else
{
for(int i=0 ; i<left.size() ; i++)
{
distance = abs(curr_pos - left[i]);
curr_pos = left[i];
seek_sequence.push_back(curr_pos);
seek_count = seek_count + distance;
}
distance = abs(curr_pos - 0);
curr_pos = 0;
seek_sequence.push_back(curr_pos);
seek_count = seek_count + distance;
for(int i=0 ; i<right.size() ; i++)
{
distance = abs(curr_pos - right[i]);
curr_pos = right[i];
seek_sequence.push_back(curr_pos);
seek_count = seek_count + distance;
}
}
cout<<"\nSeek Count : "<<seek_count;
cout<<"\nSeek Sequence: ";
for(int i=0 ; i<n+1 ; i++)
cout<<seek_sequence[i]<<" ";
}