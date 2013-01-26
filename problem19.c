/* problem 19-1 -- lina version Question */
/* How many Sundays fell on the first month of each year during the twentieth century (1 Jan 1901 to 31 Dec 2000)? */

// written by lina on Sat Jan 26 22:31:09 SGT 2013
// 


#include <stdio.h>

int return_days(int year){
    if((year%4 == 0 && year%100 !=0 )|| year%400 == 0){
        return 366;
    }else{
        return 365;
    }
}

int main(){
    
    int i; 
    int days = 0; 
    int sunday = 0; // Total Sundays of the first month
    int firstSunday = 0; //Total Sunday on the first day of the first month

    for(i=1900;i<2000;i++){
        
        days += return_days(i); 

        if(days%7 == 0 || days%7 == 1 || days%7 == 2 || days%7 == 3){
            sunday += 4;
            printf("%d %d\n",i+1, 4);
        }
        if(days%7 == 4 || days%7 == 5 || days%7 == 6){
            sunday += 5;
            printf("%d %d\n", i+1, 5);
        }

        if((days+1)%7 == 0){
            firstSunday += 1;
                    }
        printf("%d\n",sunday);
 
    }

        printf("%d\n",firstSunday);
        return 0;
  
}
