//===========================================
//  problem69_1.C 
//
//  written by lina <lina.oahz@gmail.com> 
//  start: Sun Mar  3 12:48:33 SGT 2013
//    end: Sun Mar  3 13:25:50 SGT 2013
//
//  This is a brust-force one. For more elegant 
//  solution see problem69_2.C which is based on
//  http://en.wikipedia.org/wiki/Euler%27s_totient_function
//
//============================================

//============================================
// Inculde
//============================================

#include <iostream>

using namespace std;

//============================================
// main code area
//============================================

#define N 1000000

int relatively_prime_no(long n){
    int count = 1;
    for(int i=1; i<n; i++){
        for(int j=2; j<i; j++)
            if(i%j == 0 && n%j ==0){
                i++;
                break;
            }
         if(n % i != 0)        
            count++;
        }
    return count;
}


int main(){
    
    int i;

    int maxi = 1;

    float max = 2.0;

    for(i=2; i<=N;i++){
        cout << i << endl;
        if( max < (float)i/relatively_prime_no(i)){
            max = (float)i/relatively_prime_no(i);
            maxi = i;
        }
    }
        
    cout << maxi << endl;
    
    return 0;
}


