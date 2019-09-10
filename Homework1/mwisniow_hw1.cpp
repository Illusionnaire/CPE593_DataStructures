/*
    Author: Marcin Wisniowski

    I pledge my honor that I have abided by the Stevens Honor System


    Sources: 
    * 3rd edition textbook, pg 390-396
    * https://www.geeksforgeeks.org/longest-common-subsequence-dp-using-memoization/
*/

// The two files are named within the variables. Change if necessary.


//Problem Statement and pseudo-code explanation:
// Input both files into two arrays of strings (lengths n and m)
// Check string1 values to string2 values progressively.
// If the values aren't equal, keep one constant and move the other over.
    //Recursively call this for both paths and check for higher LCS at end
// If the values are equal, move both over by one and add 1 to an array that keeps the longest length value
    //Work backwards and end when there is no more string to do, from length to 0.
// Using memoization, keep a table to remove redundant checks if plausible
// This means I need another array of length (n*m max) to put values into


#include <iostream>
#include <fstream>
#include <string>
#include <cstring> //needed for memset
using namespace std;

//--------------FILE VARIABLES HERE--------------
string finput1 = "file1.txt";
string finput2 = "file2.txt";
//-----------------------------------------------

string readFile(const string& filename){
    char c;
    string string1;

    ifstream File;
    File.open(filename);
    if(!File){
        cout << "File not found";
        return 0;
    }
    while (File >> c){
        string1 += c;
    }
    File.close();

    return string1;
}

int LCS(const string& a, const string& b, int x, int y, int* memo, const int& lenx, const int& leny){

    if (x == 0 || y == 0){
        return 0;
    }

    //If value was already set before, just return that value, do not get it again
    if(memo[(lenx*(y-1))+(x-1)] != -1){
        return memo[(lenx*(y-1))+(x-1)];
    }

    //Working from the back of the string, see if the values are equal
    if (a[x-1] == b[y-1]){
        memo[(lenx*(y-1))+(x-1)] = 1 + LCS(a,b, x-1, y-1, memo, lenx,leny);

        return memo[(lenx*(y-1))+(x-1)];
    }
    //If the values aren't equal, see which path leads to the bigger LCS
    //This makes it a O(2^N) function without memoization like fibo
    else{
        memo[(lenx*(y-1))+(x-1)] = max(LCS(a,b,x,y-1, memo, lenx, leny),LCS(a,b,x-1,y, memo, lenx, leny));

        return memo[(lenx*(y-1))+(x-1)];
    }
}

int main(){
    string string1 = readFile(finput1);
    string string2 = readFile(finput2);
        int m = string1.length();
        int n = string2.length();

    //Creates an array of -1 for later validations
    int memo[m*n];
    memset(memo, -1, sizeof(memo)); // https://en.cppreference.com/w/cpp/string/byte/memset

    cout << "Length of LCS: " << LCS(string1,string2, m, n, memo, m, n);

return 0;
}