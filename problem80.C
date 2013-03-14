//===========================================
//  problem80.C 
//
//  written by lina <lina.oahz@gmail.com> 
//  start: Thu Mar 14 12:45:05 SGT 2013
//    end: Fri Mar 15 01:35:49 SGT 2013
//
//  For algorithm, please refer:
//  Frazer Jarvis's "Square roots by subtraction"
//  www.afjarvis.staff.shef.ac.uk/maths/jarvisspec02.pdf
//============================================

//============================================
// Inculde
//============================================

#include <iostream>
#include <gmpxx.h>
#include <math.h>
#include <cmath>

using namespace std;

//============================================
// main code area
//============================================

int sum_of_digits(int );

int main(){

    int result = 0;

    for(int i=1; i<=100; i++)
        if((int)sqrt(i) * (int)sqrt(i) != i)
            result += sum_of_digits(i);
        
    
    cout << result << endl;        

    return 0;
}

int sum_of_digits(int n ){
    
    mpz_t a, b, limit;

    mpz_init(a);
    mpz_init(b);
    mpz_init(limit);

    mpz_set_ui(a,5*n);
    mpz_set_ui(b, 5);
    mpz_ui_pow_ui(limit, 10, 101);

    while( mpz_cmp(b,limit) < 0){
        if(mpz_cmp(a,b) >= 0){
            mpz_sub(a, a, b);            
            mpz_add_ui(b, b, 10);

        }else{
            mpz_mul_ui(a, a, 100);
            mpz_fdiv_q_ui(b, b, 10);
            mpz_mul_ui(b, b, 100);
            mpz_add_ui(b, b, 5);
        }
        
    }
    

    int sum = 0;
    
    mpz_fdiv_q_ui(b,b,10);

    while( mpz_cmp_ui(b,0) > 0 ){
        mpz_t r;
        mpz_init(r);
        mpz_fdiv_r_ui(r,b,10);
        mpz_fdiv_q_ui(b,b,10);
        sum += mpz_get_ui(r);
    }
    mpz_clear(a);
    mpz_clear(b);
    mpz_clear(limit);

    return sum;
}

