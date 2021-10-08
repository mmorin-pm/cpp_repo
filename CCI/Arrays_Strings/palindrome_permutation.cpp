#include <iostream>
#include <string>
#include <map>

using namespace std;

//Given a string write a function that checks if it is a permutation of a palindrome
//Ignore spaces, casing, and non letter characters


//1) sort the chars and check that they pair up or have one alone (even or odd length)
//2) No need to sort! check that in an even word all chars have even amounts, and in an odd word one char has odd count
//   use map and iterate through the word and keep track.
//3) Use bit map (pro strat): Ints have 4 bytes (32bits) which is more than in the alphabet so just toggle each bit when you see
// the charater as you parse the string. at the end if your bit vector is 0 or 1 you know you have a palindrome.
//Note: A good hybrid between 2 and 3 is to use a boolean array or vector instead of bits in an int

//method 2)
bool palindrome_perm(string words){
    std::map<char,int> tracker;
    int oddCount = 0;
    for(char c : words){
        if(tracker.find(c) != tracker.end()){
            tracker[c]++;
            if(tracker[c]%2){
                oddCount++;
            }else{
                oddCount--;
            }
        }else{
            tracker.insert({c,1});
            oddCount++;
        }
    }
    if(words.size()%2){
        if(oddCount == 1) return true;
    }else{
        if(oddCount == 0) return true;
    }
    return false;
}

//method 3: bit vector tracker
bool check_less_than_2(int vect);
int create_bit_vector(string words);

bool palindrome_perm2(string words){
    int bitvector  = create_bit_vector(words);
    return check_less_than_2(bitvector);
}

bool check_less_than_2(int vect){
    return ((vect & (vect-1))== 0);
}

int create_bit_vector(string words){
    int bits = 0;
    for(char c : words){
        int shift = 1 << (c - 97);
        bits ^= shift;
    }
    return bits;
}

int main(){

    string result = (palindrome_perm2("marcelecram")) ? "Yes it is a Pal Perm!" : "No it is not a Pal Perm...";

    cout << result << endl;

    return 0;
}