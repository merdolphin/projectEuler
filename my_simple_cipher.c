/* my_simple_cipher.c */

// written by lina <lina.oahz@gmail.com> 
// start: Sat Feb 16 00:52:19 SGT 2013
//   end:

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

    char *password;
    char *text;
    text = malloc(1000);
    int index = 0;

    FILE *fp;

    fp = fopen(argv[0], "r");
    
    printf("Please enter the password, at least 6 letters\n");
    password = malloc(30);

    gets(password);

    while(fscanf(fp,"%c",&text[index++]) != EOF){
        printf("%c",text[index]);
    }
    

    return 0;
}


