#include <stdio.h> 
#include <unistd.h>  
void main()
{ 
  int pi_d ; 
  int pid ; 
  pi_d = fork(); //create new process 
  if(pi_d == 0)  { 
    printf("Child Process A:\nPID: %d\nPPID: %d\n",getpid(),getppid()); 
  } 
  if(pi_d > 0)  { 
    pid = fork(); 
    if(pid > 0)  { 
      printf("\nParent Process:\nPID:%d\nPPID: %d\n",getpid(),getppid()); 
    } 
    else if(pid == 0)  { 
      printf("Child Process B:\nPID: %d\nPPID: %d\n",getpid(),getppid()); 
    } 
  } 
}
