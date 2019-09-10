/*
    Author: Marcin Wisniowski

    I pledge my honor that I have abided by the Stevens Honor System

    I have used the 3rd edition textbook to help solve this problem, pg 390-396
*/

// The two files are named within the variables. Change if necessary.


//Problem Statement and pseudo-code explanation:
// Input both files into two arrays of strings (lengths n and m)
// Embed a for loop inside a for loop to check (n*m) amount of values to each other
// If the values aren't equal, keep one constant and move the other over.
// If the values are equal, move both over by one and add 1 to an array that keeps the longest length value.
// Using memoization, keep a table to remove redundant checks if plausible
// This means I need another array of length (n*m max) to put values into


#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string finput1 = "file1.txt";
string finput2 = "file2.txt";

int main(){
    char c;
    string string1;
    string string2;

    ifstream File;
    File.open(finput1);
    if(!File){
        cout << "File not found";
        return 1;
    }
    while (File >> c){
        string1 = string1 + c;
    }
    File.close();

    cout << string1;






return 0;
}