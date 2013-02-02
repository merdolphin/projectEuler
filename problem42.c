/* problem42.c */

// written by lina <lina.oahz@gmail.com> 
// start: Sat Feb  2 14:13:12 SGT 2013
//   end: Sat Feb  2 15:00:20 SGT 2013

#include <stdio.h>
#include <stdlib.h>

int is_triangle(float s){
    
    int n=1;
    
    if(s == 1)
        return 1;

    while(n<s){
        n++;
        if((double)1/2*n*(n+1) == s)
            return 1;
    }
    return 0;
}


int main(){

    FILE *fp;
    char **words;
    int j, k, index = 0;
    int count = 0;
    fp = fopen("words.txt", "r");

    words = malloc(2000* sizeof *words);
    words[index] = malloc(16);

    while(fscanf(fp, "\"%[A-Z]\",", words[index]) != EOF)
         words[++index] = malloc(16);
          

    for(j=0; j<index; j++){
        int s = 0;
        for(k=0; words[j][k]; k++)
            s += words[j][k]-'A'+1;
        
        if(is_triangle(s))
            count ++;
                
    }

    printf("%d\n", count);
    free(words[index]);
    free(words);
    return 0;
}
