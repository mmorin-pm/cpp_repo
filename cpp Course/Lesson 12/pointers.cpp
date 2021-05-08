#include <iostream>
#include <vector>

using namespace std;

int main(){

    // all pointers initialized to nullptr
    int *p1 {nullptr};
    //string *p2 {nullptr};
    //vector <string> *p3 {nullptr};

    int value {100};
    int value1 {11};


    p1 = &value;

    cout << p1 << endl;
    cout << *p1 << endl;
    p1 = &value1;
    cout << *p1 << endl;

    string s1 {"Marcel"};
    string s2 {"Marcel"};

    string *m1 {&s1};
    string *m2 {&s2};
    string *m3 {&s1};

    cout << (m1 == m2) << endl; //false as they are pointing to different addresses
    cout << (m1 == m3) << endl; //tru as both m1 and m3 point to address &s1
    


    return 0;
}