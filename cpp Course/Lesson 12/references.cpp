#include <iostream>
#include <vector>

using namespace std;

int main(){

    vector<string> names {"Marcel" ,"Laure", "Emile"};

    for (auto str: names)
        str = "xxx";    // this wont work as str is a copy of each entry in names
    
    for (auto str: names)
        cout << str << endl; // will still print out original initialized names

    for (auto &str: names)
        str = "Blah...";

    for (auto const &str: names) // const because we accesing values by reference but just displaying names so make then const
        cout << str << " "; //s

    return 0;
}