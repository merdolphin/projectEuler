/* pthread_example1.c */

// written by lina <lina.oahz@gmail.com> on Mon Jan 28 23:03:11 SGT 2013
//

#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 8

void *PrintHello(void *threadid){
    long tid;
    tid = (long) threadid;
    printf("Hello world! It's me, thread #%ld!\n", tid);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]){
    
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;
    
    for(t=0; t<NUM_THREADS; t++){
        printf("In main: creathing thread %ld\n",t);
        rc = pthread_create(&threads[t], NULL, PrintHello, (void *)t);
        if(rc){
            printf("Error; return code from pthread_create() is %d\n",rc);
            //exit(-1);
        }
    }

    pthread_exit(NULL);

    return 0;
}

