#include <iostream>
#include <string>

using namespace std;

//Given a string write a function that checks if it is a permutation of a palindrome
//Ignore spaces, casing, and non letter characters


//1) sort the chars and check that they pair up or have one alone (even or odd length)
//2) No need to sort! check that in an even word all chars have even amounts, and in an odd word one char has odd count
//   use map and iterate through the word and keep track.
//3) Use bit map (pro strat): 
bool palindrome_perm(string words){


    return true;
}

int main(){

    string result = (palindrome_perm("marcel")) ? "Yes it is a Pal Perm!" : "No it is not a Pal Perm...";

    cout << result << endl;

    return 0;
}