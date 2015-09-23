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

   gettimeofday(&tv1, NULL);
   pthread_create(&id, NULL, thread_f, &time);
   pthread_join(id, NULL);
   gettimeofday(&tv3, NULL);

   printf("thread create %ld us termination %ld\n", 
          (tv2.tv_sec - tv1.tv_sec)*1000000UL+
          (tv2.tv_usec - tv1.tv_usec),
          (tv3.tv_sec - tv2.tv_sec)*1000000UL+
          (tv2.tv_usec - tv1.tv_usec));

   return 0;
}

