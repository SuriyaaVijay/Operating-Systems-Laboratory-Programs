#include <pthread.h>
#include <stdio.h>
void *printmsg(){
printf("\nPrinting function has been called");
}
int threadcompare(){
pthread_t t1;
pthread_create(&t1,NULL,&printmsg,NULL);
return (pthread_equal(t1,pthread_self()));
}
void threadfunc(){
pthread_t thread1;
pthread_create(&thread1,NULL,&printmsg,NULL);
pthread_join(thread1,(void *)pthread_self());
}
void thread_detach(){
pthread_t thread_2;
pthread_create(&thread_2 , NULL , &printmsg , NULL);
printf("detach Operation");
pthread_detach(pthread_self());
}
int main(){
threadfunc();
if (threadcompare()) printf("\nThreads are equal");
else printf("\nThreads are not equal");
thread_detach();
printf("\nThread detached\n");
return 0;
}