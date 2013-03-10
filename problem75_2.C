//===========================================
//  problem75_2.C 
//
//  written by lina <lina.oahz@gmail.com> 
//  start: Tue Mar  5 23:34:17 SGT 2013
//    end:
//
//============================================

//============================================
// Inculde
//============================================

#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
using namespace std;

//============================================
// main code area
//============================================

#define L 15e5

bool only_one_triangle(long );
bool have_cd(long , long );

int main(){
    
    long l=120;
    if(only_one_triangle(l))
        cout << l << endl;

    return 0;
}

bool only_one_triangle(long l){
    
    int m, n;
    int result = 0;

    vector<long> va;

    for(m=2; m<sqrt(l/2); m++){
        
        //if( result == 2 )
        //    break;

        for(n=1; n<m; n++){
            long a =0, b = 0, c = 0;
            a = 2*m*n;
            b = m*m - n*n;
            c = m*m + n*n;

            if( a+b+c <= l && l%(a+b+c) == 0 ){
                va.push_back(a);
                if(va.size()>1 && !have_cd(va[0], a)){
                    cout << a << " " << va[0] << endl;
                    return false;
                }
                result++;
            }
        }
    }

    if(result >= 1)
        return true;

}


bool have_cd(long a, long b){ // have_common_divisor
    
    long mini= a<b ? a:b;

    for(int i=2; i<mini; i++)
        if(a%i == 0 && b%i == 0)
            return true;
    return false;
}
