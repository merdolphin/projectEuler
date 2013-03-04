#include <iostream>
#include <iomanip>

using namespace std;


int main(){

    double a = 0.428571285714;
    double b = 0.428571285713;

    if(a > b) 
        cout << " works " << endl;

    a = (double) 428570/999997;
    b = (double) 428567/999990;
    
    cout << setprecision(12) << a << endl;
    cout << setprecision(12) << b << endl;

    if(a > b) 
        cout << " works again " << endl;


    return 0;    
}
