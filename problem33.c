/* problem33.c */

// written by lina <lina.oahz@gmail.com> 
// start: Wed Jan 30 22:50:37 SGT 2013
//   end: Thu Jan 31 13:51:34 SGT 2013
// I am confused the unorthordictal question. 

#include <stdio.h>
#include <stdlib.h>


unsigned int denominator = 1;


int is_canceling_fraction(unsigned int a, unsigned int b){
    
    //int k, m;
    //printf("%u %u\n",a,b);
    char *bufa;
    char *bufb;
    
    bufa = malloc(2*sizeof(char));
    bufb = malloc(2*sizeof(char));

    snprintf(bufa, sizeof bufa, "%u", a);
    snprintf(bufb, sizeof bufb, "%u", b);

    //printf("%f\n",(double)a/(double)b);
            
        if( (double)a/b == (double)(bufa[0]-'0')/(bufb[0]-'0') )
            if(bufa[1]-'0' == bufb[1]-'0' && bufa[1]-'0' != 0){
                //printf("%d %d\n", a, b);
                denominator *= (bufb[0]-'0');
                return 1;
                }
        
        if( (double)a/b == (double)(bufa[0]-'0')/(bufb[1]-'0') )
            if(bufa[1]-'0' == bufb[0]-'0' && bufa[1]-'0' != 0){
                //printf("%d %d\n", a, b);
                denominator *=  (unsigned int)(bufb[1]-'0');
                return 1;
        }
        if( (double)a/b == (double)(bufa[1]-'0')/(bufb[0]-'0') )
            if(bufa[0]-'0' == bufb[1]-'0' && bufa[0]-'0' != 0){
                //printf("%d %d\n", a, b);
                denominator *=  (unsigned int)(bufb[0]-'0');
                return 1;
            }
        if( (double)a/b == (double)(bufa[1]-'0')/(bufb[1]-'0') )
            if(bufa[0]-'0' == bufb[0]-'0' && bufa[0]-'0' != 0){
                //printf("%d %d\n", a, b);
                denominator *= (unsigned int)(bufb[1]-'0');
                return 1;
            }
    free(bufa);
    free(bufb);
    return 0;
}

unsigned int common_terms(unsigned a, unsigned b){
    
    int i, min;
    //printf("common_terms func receives %u %u common terms.\n",a,b);
    min = a>b?a:b;

    if(a%b == 0){
        return a;
    }
    if(b%a == 0){
        return b;
    }
    if(a%b != 0 && b%a != 0 ){
        for(i=2; i<min; i++){
            if(a%i == 0 && b%i == 0){
                 //printf("common defactor is %d\n",i);
                 //printf("common term is %d ",(a/temp)*(b/temp)*temp);
                 return (a/i)*(b/i)*i;
            }
            if(i==min){
                return a*b;
            }
        }
        }
    return 1;
}

int main(){

    unsigned int i, j;
  
    for(i=10; i<99; i++){
        for(j=i+1; j<=99; j++){
            if(is_canceling_fraction(i,j)){
                printf("%u %u\n",i,j);
            }
            //printf("%u\n", (is_canceling_fraction(i,j)));
            //denominator *= is_canceling_fraction(i,j);
            }
            //if(is_canceling_fraction(i,j)){
             //    printf("%u %u\n",i,j);
            //     denominator = common_terms(denominator,j);
             //    printf("lowest fraction is %d\n",common_terms(denominator,j));         //
            // }
        
    }
    printf("%u\n",denominator);

    return 0;
}
