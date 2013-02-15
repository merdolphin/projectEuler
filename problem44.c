/* problem44.c */

// written by lina <lina.oahz@gmail.com> 

///////////////// log ////////////////////////////
// start: Sat Feb  2 21:14:52 SGT 2013
//   end: Sat Feb  2 21:56:01 SGT 2013
// updated to thread version on Sun Feb  3 00:38:06 SGT 2013
// last updated the "join"   on Mon Feb  4 20:44:32 SGT 2013
// fixed the sqrt bug.       on Mon Feb  4 23:29:25 SGT 2013
/////////////////////////////////////////////////////////

// gcc -Wall -O3 -o problem44 problem44.c -lpthread -lm

#include <stdio.h>
#include <math.h>
#include <pthread.h>

#define NUM_THREADS 16
#define M 100000000

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
int minD = 1000;

long formula(long n){

    return n*(3*n-1)/2;
}

int is_pentagonal(long s){
    unsigned delta = sqrt(1+24*s);
 
    if( delta*delta == (1+24*s) && (1+ delta)%6 == 0)
               return 1;
    
    return 0;
}

void *look_for_min(void *threadid){
    
    long tid;
    tid = (long) threadid;
    
    long start, end;
    long j, k;
    
    start = tid*M/NUM_THREADS + 1;
    end = start + M/NUM_THREADS -1;

    for(j=start; j<end; j++){
        long sum = 0, differences = 0;
        for(k=j+1; k<M; k++){
            sum = formula(j) + formula(k);
            differences = formula(k) - formula(j);
            if(is_pentagonal(sum) && is_pentagonal(differences))
                if(sum - differences <= minD){
                    pthread_mutex_lock(&mutex1);
                    minD = sum - differences;
                    pthread_mutex_unlock(&mutex1);
                }
        }
        
        //printf("%d\n", formula(i));
    }
    printf("%d\n", minD);
    pthread_exit(NULL);
}


int main(int argc, char *argv[]){
    
    pthread_t threads[NUM_THREADS];
    
    int rc;
    long t;
    
    for(t=0; t<NUM_THREADS; t++){
        rc = pthread_create(&threads[t], NULL, look_for_min, (void *)t);
        if(rc)
            printf("Error; return code from pthread_create() is %d\n", rc);
        }

     for(t=0; t<NUM_THREADS; t++){
         pthread_join(threads[t], NULL);
     }
    
    printf("final mini D is: %d\n", minD);

    pthread_exit(NULL);

    return 0;
}
