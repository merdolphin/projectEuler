//===========================================
//  problem68.C 
//
//  written by lina <lina.oahz@gmail.com> 
//  start: Sat Mar  2 22:21:08 SGT 2013
//    end: Sun Mar  3 00:39:51 SGT 2013
//
//============================================

//============================================
// Inculde
//============================================

#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>

using namespace std;

//============================================
// main code area
//============================================

int find_min_index(int * array, int i, int j){
    int k;
    int minIndex = i;
    int temp = array[i];
    for(k=i+1; k<=j; k++)
        if(array[k] < temp){
            temp = array[k];
            minIndex = k;
        }
    return minIndex;
}

int main(){
    
    int digits[11];
    int i;

    for(i=1; i<=10; i++)
        digits[i-1] = i;
    
    int sets[5][3]= {{5,0,4}, \
                     {9,4,3}, \
                     {8,3,2}, \
                     {7,2,1}, \
                     {6,1,0}};    
        
    long max = 1;  
          
    do{
        stringstream sstemp;
           
        // only keep those each line adding to a common value

        int tmp[5] = {0};
         
        for(i=0; i<5; i++)
            for(int j=0; j<3; j++)
                tmp[i] += digits[ sets[i][j] ];
                      
        for(i=0; i<5; i++)
            for(int j=i; j<5; j++)
                if(tmp[i] != tmp[j])
                    goto d;
        
        // only keep the 16-digit string 
        
        
        for(i=0; i<5; i++)
            for(int j=0; j<3; j++)
                sstemp << digits[ sets[i][j] ];
        
        if(sstemp.str().length() == 16){
                        
            //find numerically lowest external node as a starting point
            
            int k = find_min_index(digits,5,9); //4, 9 the external array index
           
            for(i=0; i<5; i++)
                if(sets[i][0] == k)
                    break;
            
            // constitute the clockwise concatenating of each group

            stringstream nsstemp;

            if(i>0){
                for(int m = i; m<5; m++)
                    for(int j=0; j<3; j++)
                        nsstemp << digits[ sets[m][j] ];
                for(int m=0; m<i; m++)
                    for(int j=0; j<3; j++)
                        nsstemp << digits[ sets[m][j] ];
            }
            if(i==0)
                for(int m = 0; m<5; m++)
                    for(int j=0; j<3; j++)
                        nsstemp << digits[ sets[m][j] ];
            
            // find the maximum 16-digit string for a "magic" 5-gon ring            
            
            long temp;
            nsstemp >> temp;
            max = temp > max ? temp : max;
        }
        

        d:;
    }while(next_permutation(digits, digits+10));
        
    cout << max << endl;

    return 0;
}


