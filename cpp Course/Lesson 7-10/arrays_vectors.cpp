#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int value = 99;
    int test_scores [5] {1, 2, 3, 4, 53};
    test_scores[4] = value; //we are assigning the value of "value" to the last index
    //if we change value here it wont affect test_scores[4] above (pointers would though)
    value = 999;
    //int test_scores [] {1, 2, 3, 4, 53}; //alternative no need to array size in []
    int test_scores2 [100] {0}; // Init all to 0 (very useful)

    cout << "Last index of test_scores is " << test_scores[4] << endl;
    cout << "test_scores2 first index is " << test_scores2[0] << endl;

    cout << "notice printing test_scores we get the memory address at the head of the array: " << test_scores; 
    
    //vector <int> scores; //empty
    //vector <int> scores (5); //5 entries/index all init to zero
    vector <int> scores {1,2,3,4,5};
    cout << "\nLast index of vector value: " << scores[4] << endl; //using array syntax
    scores.push_back(value);
    cout << "Last index of vector value after push_back: " << scores.at(5) << endl; //using at method to get value

    return 0;
}