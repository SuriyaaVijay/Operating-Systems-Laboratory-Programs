#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main()
{
int pid, state;
printf("\nBefore the fork :\n");
if ((pid =fork() != 0))
{
   printf("Parent: \n");
   wait(&state);
}
else
{
   printf("Child:\n");
   execl("./child", "child",NULL);
   perror("Error execution");
}
printf("After fork state = %d\n",state);
printf("PID child = %d Terminated\n", pid);
return 0;
}
