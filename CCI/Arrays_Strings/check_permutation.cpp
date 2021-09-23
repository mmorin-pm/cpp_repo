#include <iostream>
#include <chrono>
#include <string>

using namespace std;
using namespace std::chrono;

//Given two string write a method to determine if one is a permutation of the other

bool check_permutation(string a, string b){
    if(a.size() != b.size()) return false;
    for(char c : a){
        auto n = b.find(c);
        if(n == std::string::npos)
            return false;
        b.erase(n,1);
    }
    return true;
}

// I really like this solution as it doesn't rely on any sorts or finds
bool check_permutation_2(string a, string b){
    if(a.size() != b.size()) return false;

    int char_array[128] {0};

    for(char c : a){ //increment char_array
        char_array[c]++;
    }

    for(char c : b){ //decrement char_array
        if(char_array[c] == 0) return false;
        char_array[c]--;
    }
    return true;
}

int main(){
    auto start = std::chrono::high_resolution_clock::now();

    string result1 = (check_permutation("qwertyuiopasdfghjkl;'zxcvbnm,./=-0987654321`~!@#$%^&*()_+","qwertyuiopasdfghjkl;'zxcvbnm,./=-0987654321`~!@#$%^&*()_+")) ? "Yes" : "No";
    auto stop1 = std::chrono::high_resolution_clock::now();

    string result2 = (check_permutation_2("qwertyuiopasdfghjkl;'zxcvbnm,./=-0987654321`~!@#$%^&*()_+","qwertyuiopasdfghjkl;'zxcvbnm,./=-0987654321`~!@#$%^&*()_+")) ? "Yes" : "No";
    auto stop2 = std::chrono::high_resolution_clock::now();
    cout << "1) Are they permutations??...   " << result1 << endl;

    cout << "2) Are they permutations??...   " << result2 << endl;



    auto duration1 = duration_cast<microseconds>(stop1 - start);
    auto duration2 = duration_cast<microseconds>(stop2 - stop1);
    cout << duration1.count() << endl;
    cout << duration2.count() << endl;
    printf("Time measured: %.8f seconds.\n", duration1.count() * 1e-9);
    printf("Time measured: %.8f seconds.\n", duration2.count() * 1e-9);

    return 0;
}