/* problem 19-0 */

// written by lina <lina.oahz@gmail.com> on Sat Jan 26 23:46:22 SGT 2013
//* know the question you involved well before you are locked in. 
//* or do I know the question better than before once I was cooped in. 
//* realize one thing: how many things in my life I understand them wrong 
//* and how luck I got a chance to be locked in before things gave up me.
//* Don't debug life, perhaps there in no bug in life, just needs some understanding, that's all. 

#include <stdio.h>

int days(int y, int m){
        
        switch(m){

            case 4:
            case 6:
            case 9:
            case 11:
                return 30;  

            case 2:
                if( (y%4 ==0 && y%100 !=0) || y%400 == 0){
                    return 29;
                }else{
                    return 28;}
            default:
                return 31;        
        }
}

int main(){

        int i, j;
        int sum = 0;
        int Totaldays = 0;
    
        for(i=1901;i<2001;i++){
            for(j=1;j<=12;j++){
                 
                if(Totaldays%7 == 0)
                    sum += 1;

                Totaldays += days(i,j);
               }
        }
                    
        printf("%d\n",sum);

        return 0; 
  
}
