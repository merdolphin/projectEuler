/* problem413.c */

// written by lina <lina.oahz@gmail.com> 
// start: Tue Feb  5 20:30:56 SGT 2013
//   end:

#include <stdio.h>
#include <string.h>

#define M 7


int is_one_child_num(int N){
    
    int *str;
    **str = N;
    printf("%d\n",**str);     

    return 0;    
}


int main(){

    int i = 1132451;
    if(is_one_child_num(i)){
        printf("correct\n");
    }
    return 0;
}
