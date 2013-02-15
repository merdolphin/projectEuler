/* problem59.c */

// written by lina <lina.oahz@gmail.com> 
// start: Fri Feb 15 16:58:36 SGT 2013
//   end: Sat Feb 16 00:32:46 SGT 2013
///////////// steps //////////////
//
// perl -e 'print ord(a)'  a - z 97 - 122
// "the" 116 104 101
// "The"  84 104 101
// " " 32
// ciphered ascii range: 0-94

// frenquecy analysis: 79 68 71, one is possible to be space, another is e


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(){

    FILE *fp;
    
    int *ciphered;
    
    int index = 0;

    int k1, k2=111, k3, idx = 0, m;
    int sum = 0;

    ciphered = malloc(1202 * sizeof (*ciphered));

    fp = fopen("cipher1.txt", "r");
    
    while(fscanf(fp, "%d,", &ciphered[index]) != EOF){
    
        //printf("%d %d\n", index, ciphered[index]);

        index++;
    }
    
    for(k1=97;k1<=122;k1++){
            for(k3=97;k3<=122;k3++){
                for(idx=0; ciphered[idx]; idx+=3){
                    // looking for "T(t)he"
                    if( (( (ciphered[idx] ^ k1) == 116 || (ciphered[idx] ^ k1) == 84) && (ciphered[idx+1] ^ k2) == 104 && (ciphered[idx+2] ^ k3) == 101) ||
                        ( (ciphered[idx] ^ k1) == 104 && (ciphered[idx+1] ^ k2) == 101 && ( idx>1 && ((ciphered[idx-1] ^ k3)== 116 || (ciphered[idx-1] ^ k3)== 84 ))) || 
                        (idx>=3 && ((ciphered[idx] ^ k1) == 101 && (ciphered[idx-1] ^ k3) == 104 && ( (ciphered[idx-2] ^ k2) == 116 || (ciphered[idx-2] ^ k2) == 84)))
                        ){
                        
                        printf("%d %d %d \n", k1, k2, k3);
                        
                        for(m=0; m<=10; m+=3)
                            printf("%c%c%c",(ciphered[m]^k1),(ciphered[m+1]^k2),(ciphered[m+2]^k3));
                        printf("\n");
                    }
                }
            }
    }
    
    char keys[3] = {103, 111, 100};
    int key_count = 0;
    for(idx=0; idx<index;idx++){
        //printf("%d %d %d\n",ciphered[idx],keys[key_count], (ciphered[idx] ^ keys[key_count]) );
        sum += (ciphered[idx] ^ keys[key_count++]);
        if(key_count==3)
            key_count = 0;
    }
        
    fclose(fp);
    printf("%d\n",sum);
    return 0;
}
