/* pnt_add.c */

// written by lina <lina.oahz@gmail.com> on Sun Jan 27 21:00:39 SGT 2013
// Apply the * operator to a pointer yields the values stored in the pointer-to object.
// date + 2 = &date[2];
// *(date+2) = date[2];

#include <stdio.h>

#define SIZE 4

int main(){
    
    int dates[SIZE]; // short use two bytes.
    int *pti;
    int index;
    double bills[SIZE];
    double *ptf;

    pti = dates;
    ptf = bills;

    printf("%23s %10s\n", "short","double");

    for(index=0; index<SIZE; index++){
        printf("pointers + %d: %10p %10p\n",
                            index, pti+index, ptf+index);
    }

    return 0;
}

