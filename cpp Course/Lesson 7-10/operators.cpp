#include <iostream>

using namespace std;

int main()
{

    int list [] {10, 20, 30};

    cout << list[0] << endl;
    int *value = list;
    int var = *value;
    cout << "value: " << *value << endl;
    cout << "var: " << var << endl;

    value++;
    var++;

    cout << "value: " << *value << endl; //value was incremented to list's next value
    cout << "var: " << var << endl; //var was incremented to value + 1

    double division = 11/9;
    cout << division << endl;
    double division_cast = static_cast<double>(11)/9; //makes the 11 a double and then division result will be double
    cout << division_cast << endl;

    int int_val = 10;
    double double_val = 10.1;

    if (int_val != double_val) cout << "int_val != double_val\n";
    if (int_val == static_cast<int>(double_val)) cout << "int_val == static_cast<int>(double_val)\n";


    return 0;
}