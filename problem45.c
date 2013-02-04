/* problem45.c */

// written by lina <lina.oahz@gmail.com> 
// start: Mon Feb  4 23:00:31 SGT 2013
//   end:

#include <stdio.h>
#include <math.h>

int is_triangle(long t){

    unsigned sq = sqrt(1+8*t);
    if( sq*sq == 1+8*t && (sq-1)%2 == 0)
        return 1;
    
    return 0;
}

int is_pentagonal(int p){

    unsigned sq = sqrt(1+24*p);
    if( sq*sq == 1+24*p && (sq+1)%6 == 0)
        return 1;

    return 0;
}

int is_hexagonal(int h){

    unsigned sq = sqrt(1+8*h);
    
    if( sq*sq == 1+8*h && (sq+1)%4 == 0)
        return 1;

    return 0;
}



int main(){

    int i=40756;
    
    while(1){
        if(is_triangle(i) && is_pentagonal(i) && is_hexagonal(i)){
            printf("%d\n", i);
            break;
        }
        i++;
    }

    return 0;
}
