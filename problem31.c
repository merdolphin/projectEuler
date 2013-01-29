/* problem31.c */

// written by lina <lina.oahz@gmail.com> 
// start: Tue Jan 29 15:44:51 SGT 2013
//   end: Tue Jan 29 15:54:56 SGT 2013

#include <stdio.h>

int main(){

    int j, k, l, m, n, o, p;
    int sum = 0;
    
   for(p=0;p<=1;p++)
    for(o=0; o<=2; o++)
        for(n=0; n<=4; n++)
            for(m=0; m<=10; m++)
                for(l=0; l<=20; l++)
                    for(k=0; k<=40; k++)
                        for(j=0; j<=100; j++)

                            if(p*200 + o*100 + n*50 + m*20 + l*10 + k*5 + j*2 <= 200)
                                    sum++;
            
    printf("%d\n",sum);                                
    return 0;
                                                                          
}
