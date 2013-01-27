/* problem22.c */

// written by lina <lina.oahz@gmail.com> 
// start: Sun Jan 27 14:00:24 SGT 2013
// end:   Mon Jan 28 00:34:59 SGT 2013

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int comp (const void *a, const void *b){
    return strcmp(* (char * const *)a, *(char * const *)b);
}

int main(){

   
    FILE *fp;

    char **name;
   
    int index = 0;
    int i;
    int Tsum = 0;

    fp = fopen("names.txt", "r");

    name = malloc(6400 * sizeof *name);
    name[index] = malloc(16);
    
    while(fscanf(fp, "\"%[A-Z]\",", name[index]) != EOF){
        name[++index] = malloc(16);
        //printf("%d\n",index);
        
    }   
    
    qsort(name, index, sizeof(*name)/sizeof(*name[0]),comp);
    for(i=0;i<index;i++){
        int j=0;
        int sum = 0;
        while(name[i][j] != '\0'){
                        
            sum += name[i][j]-'A'+1;
            j++;
        }
        Tsum += (i+1)*sum;
       }
     
     printf("%d\n", Tsum);

    free(name[index]);  
    fclose(fp);
    return 0;
}
