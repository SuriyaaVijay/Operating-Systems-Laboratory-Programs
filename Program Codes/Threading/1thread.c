#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>  
#include <pthread.h> 
int prod=1;
void *multi(void *param) 
{  
    int i,upper= 6;
    prod=1; 
    for(i=1;i<=upper;i++)
    	prod*=i;
    printf("Printing Product from Thread\n"); 
    pthread_exit(0); 
} 
   
int main(int argc,char *argv[]) 
{ 
    pthread_t thrid; 
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_create(&thrid,&attr,multi,argv[1]);
    pthread_join(thrid,NULL);
    printf("Product of numbers = %d\n",prod); 
    exit(0); 
}

