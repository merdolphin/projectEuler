#include <stdio.h>
#include <assert.h>
#include <limits.h>
#include <gmp.h>

int main(){
    
    int k, x, i;
    int a = sizeof(int) * 8;
    printf("Size of integers in this computer = %d bits \n", a);
    printf("The largest int reprensentable is %d\n", INT_MAX);
    printf("The smallest int reprensentable is %d\n", INT_MIN);

    long b = sizeof(long) * 8;
    printf("Size of long  in this computer = %ld bits \n", b);
    printf("The largest long reprensentable is %ld \n", LONG_MAX);
    printf("The smallest long reprensentable is %ld \n", LONG_MIN);

    
    k = INT_MAX;
    
    printf("%d + 1 = %d \n", k, k+1);

    /* Input a number x and prints its binary representation out */

    printf("Enter x:");
    scanf("%d",&x);
    printf("The binary representation LSB -- MSB is: ");
    for (i=0; i<8*sizeof(int); ++i){
        
        if(x %2 == 0)
            printf("0");
        else
            printf("1");

            x = x >> 1; // shift right by 1
      }
   
    
   printf("\n");

   return 0;

   char inputStr[1024];
    /* mpz_t is the type defined for GMP integers.
    It is a pointer to the internals of the GMP integer data structure
    */
    mpz_t n;
    
    int flag;    
    
    printf("Enter your number:");
    scanf("%1024s", inputStr);

    mpz_init(n);
    mpz_set_ui(n,0);

    flag = mpz_set_str(n,inputStr,10);
    assert (flag ==0); /* if flag is not 0 then the operation failed */

    /* print n */
    printf("n=");
    mpz_out_str(stdout, 10, n);
    printf("\n");
}
