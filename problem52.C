//===========================================
//  problem52.C 
//
//  written by lina <lina.oahz@gmail.com> 
//  start: Tue Feb 26 12:58:28 SGT 2013
//    end: Tue Feb 26 15:18:57 SGT 2013
//
//============================================

//============================================
// Inculde
//============================================

#include <iostream>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <new>

using namespace std;

//============================================
// main code area
//============================================

#define N 10000000

int main(){

    int i;
        
    for(i=100; i<N; i++){
        
        int a = floor(log10(i)) + 1;
  
        int *digits;

        digits = new int [a];
        
        int temp = i;
        for(int j=a-1; j>=0; j--){
            digits[j] = temp%10; 
            temp = temp /10;
        }
                       
        
        int * icontainer;
        int b = 1;

        for(int j=1;j<=a;j++)
            b*=j;
        
        icontainer = new int [b+1];       
        int index = 0;
        
        do{  
            int m=1;
            int temp = 0;

            for(int k=a-1; k>=0; k--){
                temp += digits[k]*m;
                m *= 10;
            }

            icontainer[index++] = temp;

        }while(next_permutation(digits,digits+a));

        int count = 0;
        for(int j=0; j<index; j++)
            if(icontainer[j] % i == 0)
                for(int k=2; k<=6; k++)
                    if(icontainer[j] / k == i)
                        count++; 
            
        if(count == 5){
            cout << i << endl;
            break; 
        }

        delete [] icontainer;
        
        digits = NULL;
        
        delete [] digits;
         
    }
       
    return 0;
}


