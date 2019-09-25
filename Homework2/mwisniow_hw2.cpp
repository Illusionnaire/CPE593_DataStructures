/*
    Author: Marcin Wisniowski

    I pledge my honor that I have abided by the Stevens Honor System

    Insert 
*/


#include <iostream>
using namespace std;

int gcd(int a, int b) 
{ 
    //Make sure a is larger
    if (a < b){
        int temp = a;
        a = b;
        b = temp;
    }

    // Base cases for GCD. 
    if (b == 0) 
       return a;
   
    return gcd(a % b, b); 
} 

int lcm(int a, int b){
    int com_den = gcd(a,b);
    return (a / com_den) * (b / com_den) * com_den;
}

int powermod(int a, int b, int r){
    int prod = 1;
    while (b > 0) {
        if (b % 2 != 0){
            prod = (prod * a) % r;
        }
        a = (a*a) % r;
        b = b / 2;
    }
    return prod;
}

int main(int argc, char *argv[]){
    int a,b,r;
    a = atoi(argv[1]);
    b = atoi(argv[2]);
    r = atoi(argv[3]);
    cout << "\nComputing GCD, LCM, and Powermod...\n\n";

    cout << "GCD: " << gcd(a,b) << endl;
    cout << "LCM: " << lcm(a,b) << endl;
    cout << "Powermod: " << powermod(a,b,r) << endl;


return 0;
}