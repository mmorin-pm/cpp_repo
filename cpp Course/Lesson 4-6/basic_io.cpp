#include <iostream>

using namespace std;

int main()
{
    cout << "Hello there!" << endl; // string data in inserted in cout
    cout << "Enter " << "your first and last name here: "; // can be chained like so

    string firstname, lastname;
    cin >> firstname >> lastname; // Can be chained (space & tab delimited/ignored)

    cout << "\nFirst name: " << firstname << endl;
    cout << "Last name: " << lastname << endl;

    return 0;
}