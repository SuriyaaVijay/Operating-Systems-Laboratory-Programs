#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main( void)
{
int pid;
int n=0;
int status;
pid= fork();
  while (n<10)
  {
	if (pid == 0)
	{
		printf("This is the child working: %d\n", n);
		n = n + 2;
		sleep(1);
	}
	else
	{
		wait(&status);
		printf("Thsis is the parent working: %d\n", n);
		n = n +3;
		sleep(1);
	}
  }
}

