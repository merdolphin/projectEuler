/* problem28.c */
/*Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows:

21 22 23 24 25
20  7  8  9 10
19  6  1  2 11
18  5  4  3 12
17 16 15 14 13

It can be verified that the sum of the numbers on the diagonals is 101.

What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?
*/

// written by lina <lina.oahz@gmail.com> 
// start: Tue Jan 29 00:23:48 SGT 2013
//   end: Tue Jan 29 11:58:04 SGT 2013

#include <stdio.h>

#define N 1001

int main(){

    int i;
    int s = 1;
    int edge = 1;

    for(i=3;i<=N;i+=2){
         
        s += i*i + i*i-(i-1) + i*i - (i-1)*2 + i*i - (i-1)*3;
        printf("%d %d\n", i, s);
    }
}
