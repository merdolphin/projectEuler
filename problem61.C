//===========================================
//  problem61.C 
//
//  written by lina <lina.oahz@gmail.com> 
//  start: Tue Feb 26 20:23:24 SGT 2013
//    end: Thu Feb 28 16:43:47 SGT 2013
//
//============================================

//============================================
// Inculde
//============================================

#include <iostream>
#include <cmath>
#include <math.h>
#include <list>

using namespace std;

//============================================
// main code area
//============================================


int eq(int a, int b, int c){
    
    int sq;

    sq = (int) sqrt(b*b-4*a*c);
    
    if(sq*sq == b*b-4*a*c && (-b + sq)%(2*a) == 0)
        return (-b+sq)/(2*a);
    return 0;    
}

bool is_triangle(int p){

    if(eq(1, 1, -2*p))
        return true;
    return false;
}

bool is_square(int p){
    
    if(eq(1, 0, -p))
        return true;
    return false;
}

bool is_pentagonal(int p){
    if(eq(3, -1, -2*p))
        return true;
    return false;
}

bool is_hexagonal(int p){
    if(eq(2, -1, -p))
        return true;
    return false;
}

bool is_heptagonal(int p){
    if(eq(5, -3, -2*p))
        return true;
    return false;
}

bool is_octagonal(int p){
    if(eq(3, -2, -p))
        return true;
    return false;
}

bool combination(int a, int b){
    int temp = a*100+b;
    if( is_triangle(temp) || is_square(temp) || is_pentagonal(temp) || is_hexagonal(temp) || is_heptagonal(temp) || is_heptagonal(temp) )
        return true;
    return false;
}

list<int> pushtolist(list<int> mylist, int a, int b){
    mylist.push_back (a*100+b);
    return mylist;
}



bool check_list(list<int> mylist){
    list<int> mynewlist;
    list<int>::iterator it=mylist.begin();
    
   do{
       if(is_triangle (*it))
            mynewlist.push_back(3);           
            
       if(is_square(*it))
            mynewlist.push_back(4);            
        
       if(is_pentagonal(*it))
            mynewlist.push_back(5);    
        
       if(is_hexagonal(*it))
            mynewlist.push_back(6);            
        
       if(is_heptagonal(*it))
            mynewlist.push_back(7);
                    
       if(is_octagonal(*it))
            mynewlist.push_back(8);
                                  
       it++;

    } while(it != mylist.end());

    mynewlist.sort();
    mynewlist.unique();

    if(mynewlist.size() == 6)
            return true;
    
    return false;
}


bool check_list_different_n(list<int> mylist){
    
    list<int> mynewlist;
    list<int>::iterator it = mylist.begin();

    int flag3 = 1;
    while(it !=mylist.end() ){
       
        if(flag3 && is_triangle (*it)){
            mynewlist.push_back( eq(1, 1, -2*(*it)) );
            flag3 = 0;
        }
        if( is_square(*it))
            mynewlist.push_back( eq(1, 0, -(*it)) );
  
        if(is_pentagonal(*it))
            mynewlist.push_back( eq(3, -1, -2*(*it)) );
        
        if(is_hexagonal(*it))
            mynewlist.push_back( eq(2, -1, -(*it)) );
        
        if(is_heptagonal(*it))
            mynewlist.push_back( eq(5, -3, -2*(*it)) );
        
        if(is_octagonal(*it))
            mynewlist.push_back( eq(3, -2, -(*it)) );
            
       it++;     
    }
    
    mynewlist.sort();
    mynewlist.unique();
    
    if(mynewlist.size() == 6)
            return true;
    
    return false;
}



int main(){
      
    for(int i=10;i<100;i++)
        for(int j=10;j<100;j++)
            if(is_octagonal(i*100+j))
                for(int k = 10; k<100; k++)
                                                                                          
                    if( combination(j,k) )

                        for(int l=10; l<100; l++)
                            if(  combination(k, l) )
                                for(int m=10; m<100; m++)
                                    if( combination(l,m))
                                        for(int n=10; n<100; n++)
                                            if( combination(m,n) && combination(n,i) ){
                                                    list<int> sixcyclelist;
                                                    list<int>::iterator it;

                                                   
                                                    sixcyclelist = pushtolist(sixcyclelist, i, j);
                                                    sixcyclelist = pushtolist(sixcyclelist, j, k);
                                                    sixcyclelist = pushtolist(sixcyclelist, k, l);
                                                    sixcyclelist = pushtolist(sixcyclelist, l, m);
                                                    sixcyclelist = pushtolist(sixcyclelist, m, n);
                                                    sixcyclelist = pushtolist(sixcyclelist, n, i);

                                                    if( check_list(sixcyclelist) )
                                                        if( check_list_different_n (sixcyclelist) ){
                                                            int sum = 0;
                                                            for(it=sixcyclelist.begin(); it != sixcyclelist.end(); it++)
                                                                sum += *it; 
                                                            cout << sum  << endl ;
                                                            
                                                    }
                                            }
                  

      return 0;
}


