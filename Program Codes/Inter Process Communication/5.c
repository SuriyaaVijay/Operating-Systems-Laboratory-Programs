#include <stdio.h> 
#include <unistd.h>  
int main()
{
int pid ;
for(int i=1;i<=10;i++) 
{ 
	 
  	pid = fork();
  	if(pid==0) 
	printf("The process with the PID %d = %d\n",i,getpid()); 
}
return 0; 
}
