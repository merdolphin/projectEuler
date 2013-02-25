/* problem32.C */

// written by lina <lina.oahz@gmail.com> 
// start: Mon Feb 25 15:22:19 SGT 2013
//   end: Mon Feb 25 18:03:14 SGT 2013

#include <iostream>
#include <sstream>
#include <algorithm>
#include <new>

using namespace std;


int check_add_s(int *p, int s){

     int i;

     if(p[0] == '\0'){
        p[0] = s;
        return 1;
     }

    for(i=0;p[i];i++)
        if(s == p[i])
            return 1;
       
    p[i] = s;   
     
    return 1;
}


int main(){
   
    int *products;
    products = new int [20];

    int num[9];

    int i;
    int sum = 0;

    for(i=0;i<9;i++)
        num[i] = i+1;

    int m;
    int k;
    do{
        int plicand, plier, prod;

        for(i=0;i<=5;i++)
            for(int j=i+1; j<8; j++){
                plicand = 0, plier = 0, prod = 0;

                m = 1;
                for(k=i; k>=0; k--){
                    plicand += num[k]*m;
                    m *= 10;
                }
                m = 1;
                for(k=j;k>i;k--){
                    plier += num[k]*m;
                    m *= 10;
                }
                m = 1;
                for(k=8;k>j;k--){
                    prod += num[k]*m;
                    m *= 10;
                }
            
            if(plicand * plier == prod)
               check_add_s(products, prod);
            }
    }while(next_permutation(num,num+9));

    for(i=0;products[i];i++)
        sum += products[i];
    
    cout << sum << endl;
    delete [] products;

    return 0;
}


