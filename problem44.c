/* problem44.c */

// written by lina <lina.oahz@gmail.com> 
// start: Sat Feb  2 21:14:52 SGT 2013
//   end: Sat Feb  2 21:56:01 SGT 2013
// updated to thread version on Sun Feb  3 00:38:06 SGT 2013
// gcc -Wall -O3 -o problem44 problem44.c -lpthread -lm

#include <stdio.h>
#include <math.h>
#include <pthread.h>

#define NUM_THREADS 4
#define M 1000000

int formula(int n){

    return n*(3*n-1)/2;
}

int is_pentagonal(int s){
    unsigned delta = sqrt(1+24*s);
 
    if( (1+ delta)%6 == 0)
               return 1;
    
    return 0;
}

void *look_for_min(void *threadid){
    
    long tid;
    tid = (long) threadid;
    
    int start, end;
    int j, k;
    int minD = 1000;
    
    start = tid*M/NUM_THREADS + 1;
    end = start + M/NUM_THREADS -1;

    for(j=start; j<end; j++){
        int sum = 0, differences = 0;
        for(k=j+1; k<M; k++){
            sum = formula(j) + formula(k);
            differences = formula(k) - formula(j);
            if(is_pentagonal(sum) && is_pentagonal(differences))
                if(sum - differences <= minD)
                    minD = sum - differences;
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

    pthread_exit(NULL);

    return 0;
}
