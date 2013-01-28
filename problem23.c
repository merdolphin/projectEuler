/* problem23.c */

// written by lina <lina.oahz@gmail.com> on Mon Jan 28 13:37:34 SGT 2013//

#include <stdio.h>

int is_abundant(int N){
    
    int i;
    int sum = 0;

    for(i=1; i<N; i++){
        if(N%i == 0)
            sum += i;
    }

    if(sum > N)
        return 1;
     
    return 0;
}


int main(){
    
    int i, j;
    long sum = 0;

    for(i=1; i<=28123; i++){
        for(j=1; j<=i/2+1; j++){
            if(is_abundant(j) && is_abundant(i-j)){
                break;
            }
	    if(j==i/2+2 || j==i/2+1){
	   	sum += i;
		printf("%d\n",i);
	   }
        }

    }

    printf("%ld\n", sum);
    return 0;

}

