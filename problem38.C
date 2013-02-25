/* problem38.C */

// written by lina <lina.oahz@gmail.com> 
// start: Mon Feb 25 12:16:23 SGT 2013
//   end: Mon Feb 25 13:25:31 SGT 2013
//* This code still needs further improvement.

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    
    int num[9];
    int i;

    int multipler[9];

    for(i=0; i<9; i++){
        num[i] = i+1;
        multipler[i] = i+1;
    }
    
    do{ 
        for(i=0;i<9;i++)
            if(num[i]%multipler[i] != 0)
                goto threeperiods;
        if(i == 9){
            for(i=0;i<9;i++)
                cout << num[i];
            cout << endl;    
        }
        threeperiods:
        
        for(i=0;i<2;i++)
            if( (num[3*i]*100 + num[3*i+1]*10 + num[3*i+2]) / multipler[i] != (num[3*i+3]*100 + num[3*i+4]*10 + num[3*i+5]) / multipler[i+1] )
                goto fourperiods;
        
        if(i==2){
            for(i=0;i<9;i++)
                cout << num[i]; 
            cout << endl;
        }
        
        fourperiods:
        if(num[0]*1000 + num[1]*100 + num[2]*10 + num[3] == (num[4]*10000 + num[5]*1000 + num[6]*100 + num[7]*10 + num[8])/2){
            for(i=0;i<9;i++)
                cout << num[i]; 
            cout << endl;    
        }
        
        }while(next_permutation(num,num+9));

    return 0;
}


