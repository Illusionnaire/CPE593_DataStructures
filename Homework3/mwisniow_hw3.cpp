/*
    Author: Marcin Wisniowski

    I pledge my honor that I have abided by the Stevens Honor System

    Used Kruger's pseudocode examples from class and wrote the code around that, see 2017S Session03 Primes
*/

#include <iostream>
using namespace std;

int powermod(int x, int n, int m){
    int prod = 1;
    while (n > 0) {
        if (n % 2 != 0){
            prod = (prod * x) % m;
        }
        x = (x*x) % m;
        n = n / 2;
    }
    return prod;
}

bool MillerRabin(int n, int k){
    int d = n-1;
    int a,r = 0;

    while (d % 2 == 0){
        d /= 2;
        r++;
    }

    for(int i = 0; i < k; i++){ //Witness Loop
    a = rand() % (n-4) + 2;
    int x = powermod(a,d,n);    

    if (x == 1 || x == n-1){
        continue;
    }
    for(int j = r; j > 0; j--){
        x = (x*x) % n;
        if (x == 1){
            return false;
        }
        if (x == n-1){
            break;
        }
    }
    if(x != n-1){
    return false;
    }
    }
    return true;




};


int main(int argc, char *argv[]){ 
    int n,k;
    bool prime;
    n = atoi(argv[1]);
    k = atoi(argv[2]);

    prime = MillerRabin(n,k);

    if (prime){
        cout << n << " is prime.";
    }
    else {
        cout << n << " is composite.";
    }

return 0;
}