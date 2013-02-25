/* problem36.C */

// written by lina <lina.oahz@gmail.com> 
// start: Mon Feb 25 13:28:47 SGT 2013
//   end: Mon Feb 25 15:19:41 SGT 2013

#include <iostream>
#include <sstream>
#include <string>
#include <new>

using namespace std;

#define N 1000000

int is_palindrome(string s){
    
    unsigned i;
    for(i=0;i<s.length()/2;i++)
        if(s[i] != s[s.length()-1-i])
            return 0;
    if(i == s.length()/2-1 || i == s.length()/2)
        return 1;
    return 0;    
}

int decTobin(int i){
    
    int *bin;
    bin = new int [32];
    int index = 0;

    while(i>0){
        bin[index++] = i%2;
        i/=2;
    }
    stringstream ss2;
    for(i=0;i<index;i++)
        ss2 << bin[i];
    
    delete [ ] bin;
     
    if(is_palindrome(ss2.str()))
        return 1;
    
    return 0;
}

int main(){
    
    int i;
    int sum = 0;
    for(i=1;i<N;i++){
        stringstream ss1;
        ss1 << i;
        if(is_palindrome(ss1.str()))
            if(decTobin(i))
                sum += i;     
    }
    
    cout << sum << endl;
    return 0;
}


