/* problem39.c */

// written by lina <lina.oahz@gmail.com> 
// start: Sat Feb  2 13:38:37 SGT 2013
//   end: Sat Feb  2 14:05:28 SGT 2013

#include <stdio.h>

#define P 1000

int main(){

    unsigned i;
    unsigned a, b, c;
    unsigned index=1, max = 1;
    
    for(i=4; i<=P; i++){
        int count = 0;
        for(a=1; a<i/3; a++)
            for(b=1; b<i/2; b++)
                if(b>=a){
                    for(c=1; c<i ; c++)
                        if(c>=b){
                            if(a+b+c == i && a*a + b*b == c*c && a+b>c && c-b<a){
                               // printf("%u %u %u %u\n", a, b, c, i);
                                count++;
                            }
                        }
                }
        if(count > max){
            index = i;
            max = count;
        }
        
        //printf("%d %d\n", count, i);
                
    }

    printf("%d %d\n", max, index);
    return 0;
}
