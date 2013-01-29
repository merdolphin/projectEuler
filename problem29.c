/* problem29.c */

// written by lina <lina.oahz@gmail.com> 
// start: Tue Jan 29 12:02:08 SGT 2013
//   end: Tue Jan 29 13:31:51 SGT 2013

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <gmp.h>

#define N 100

int main(){

    int a, b;
    int i, j, count = 0;
    int idx = 1;
    mpz_t *list;
    list = (mpz_t *) malloc(N*N*sizeof(mpz_t));

      for(a=2; a<=N; a++)
        for(b=2; b<=N; b++){
            
            //list[idx++] = (mpz_t *) malloc(sizeof(mpz_t));
           
            mpz_init_set_d(list[idx++], pow(a,b));   
        }

    for(i=0; i<idx-1; i++){
        for(j=i+1; j<idx; j++){
            //printf("%d %d %d\n",i,j,idx);
            if(! mpz_cmp(list[i],list[j])){
                break;
            }
        }
        if(j == idx)
            count++;   
        //gmp_printf("%Zd %d %d\n",list[i],i,j);

    
    }

    printf("%d\n",count);
    free(list);
    return 0;
}
