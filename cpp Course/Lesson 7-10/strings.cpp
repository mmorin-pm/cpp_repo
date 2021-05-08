#include <iostream>

using namespace std;

int main()
{

    string s1;    // Empty (strings are automatically initialized to being empty, just null terminated)
    string s2 {"Marcel"};   // Marcel
    string s3 {s2};     // Marcel
    string s4 {"Marcel", 3};    // Mar
    string s5 {"Marcel", 0, 2}; // Ma
    string s6 {3, 'X'};     // XXX

    string part1 = "hello";
    string part2 = "person";
    string sentence;
    sentence = part1 + " " + part2 + " nice to meet you"; // Mix of C-Style strings and std Strings is OK
    //sentence = "hey " + "how are you?"; // this is illegal because you cannot concatenate two c-style strings

    cout << sentence << endl;
    cout << sentence.length();

    return 0;
}