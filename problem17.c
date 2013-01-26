/* problem 17 */
// written by lina on Sat Jan 26 16:25:58 SGT 2013

/* some part is wrong */


#include <stdio.h>

int main(){
    
    int i, j;

    int sum = 0, a=0;
    
    /* one, two, three, four, five, six, seven, eight, nine, ten */
    
    unsigned wc1[] = {3,3,5,4,4,3,5,5,4,3};
    
    /* eleven, twelve, thirteen, fourteen, fifteen, sixteen, seventeen, eighteen,nineteen, twenty */

    unsigned wc2[] = {6,6,8,8,7,7,9,8,8,6};

    /* 20, 30 ... 90 */
    
    unsigned wc3[] = {6,6,5,5,5,7,6,6};

    for(i=0; i<10; i++){
        a += wc1[i]; //1-10
        a += wc2[i]; //11-20
    }
    for(i=0; i<8; i++){
        a += wc3[i]; //20, 30..90
    }

    for(i=0;i<8;i++)  
        for(j=0;j<9;j++){
            a += wc3[i]+wc1[j]; 
        }
       
    sum = a; // 1- 99

    for(i=0; i<9; i++){
        sum += (wc1[i]+10)*a; // one hundred and 
     }

     for(i=0; i<9; i++){
        sum += wc1[i] + 7; // 100, 200, ...900
     }

    sum += 13;

    printf("%d\n",sum);
    return 0;

}
