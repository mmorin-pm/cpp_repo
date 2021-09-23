#include <iostream>

using namespace std;

//****************************************************************************************************
//Implement an algo that determines if a string has all unique characters
//Try and not use additional data structs other than string
//****************************************************************************************************

//Notes:
//ASCII vs Unicode
//ASCII has 2^7 max characters it can represent
//Unicode contains way more charaters (UTF-8 Unicode defines 8 bits to represent characters)
//Unicode UTF-8 uses the same first 128 (2^7) chars as ASCII so they are infact compatible

bool isUnique(string words){
    if(words.length() > 128) return false; //This is under the assumption that we are using ASCII
    //If the word is greater than the total number of ASCII characters then there must be duplicates
    bool char_found[128] {false};

    for(char c : words){                // Our solution will be O(n) {actually O(128)} complexity as we just need
        if(char_found[c] == true){      // to go through all the chars once. A brute force approach
            return false;               // would have cost us O(n^2)
        }
        char_found[c] = true;
    }
    return true;
}


int main(){

    string user_string;

    cout << "Enter string: ";
    cin >> user_string;

    //Brute force would have us compare every character to each other and see if we have a match
    //A faster more elegant way would have us set an array of booleans representing 0-127
    //when a character is found in the string we set its ASCII numerical value to true in the boolean array

    if(isUnique(user_string)){
        cout << "String contains unique chars!!" << endl;
    }else{
        cout << "String does NOT contain unique chars..." << endl;
    }
    return 0;
}