/* problem26.C */

// written by lina <lina.oahz@gmail.com> 
// start: Mon Feb 25 18:20:38 SGT 2013
//   end: Mon Feb 25 21:45:45 SGT 2013

#include <iostream>

using namespace std;

int recurring_cycle_length(int n, int m){
    
    int remainders[n];
    int i=0;
    int index = 0;
    
    remainders[0] = m%n;
    
    if(remainders[index] == '\0')
        return 0;

    while(1){
        for(i=0;i<index;i++)
            if(remainders[index]*m%n == remainders[i]){            
                return index == 1 ? index: index-i+1;
                break;
            }
         
         if(remainders[index] == 0)
             return 0;       
         remainders[index+1] = remainders[index]*m%n;
         index++;
    }    
}

int main(){

    int i;
    int longest = 1;
    int d;

    for(i=999;i>10;i--){
        if(i<longest)
            break;

        if(recurring_cycle_length(i,1000) > longest){
            longest = recurring_cycle_length(i,1000);
            d = i;
        }
         
    }
    
    cout  << d << endl;
    
    return 0;
}


