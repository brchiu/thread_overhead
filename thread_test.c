#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <sys/time.h>

struct timeval tv1, tv2, tv3;

void *thread_f(void *user)
{
   gettimeofday(&tv2, NULL);
   return (void *)0;
}

int main(int argc, char *argv[])
{
   pthread_t id;
   unsigned int time_creation, time_termination;

   gettimeofday(&tv1, NULL);
   pthread_create(&id, NULL, thread_f, &time);
   pthread_join(id, NULL);
   gettimeofday(&tv3, NULL);

   time_creation = (tv2.tv_sec - tv1.tv_sec) * 1000000UL +
                   (tv2.tv_usec - tv1.tv_usec);
   time_termination = (tv3.tv_sec - tv2.tv_sec) * 1000000UL +
                      (tv3.tv_usec - tv2.tv_usec);

   printf("thread create %ld us termination %ld total %ld\n", 
          time_creation, time_termination, time_creation + time_termination);

   return 0;
}

