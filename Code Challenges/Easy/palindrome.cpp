#include <iostream>
#include <math.h>
#include <deque>

bool isPalindrome(int x){
    if(x < 0)
        return false;
    std::deque<int> list;
    int previous_mod = -1;
    int index = 0;
    int mod = x % (int)pow(10,index+1);
    while(mod != previous_mod){
        list.push_back(mod/pow(10,index));
        std::cout << (int)(mod/pow(10,index)) << ", ";
        index++;
        previous_mod = mod;
        double temp = pow(10,index+1);
        mod = x % (int)temp;
        std::cout << "end of while.." << std::endl;
        //mod = x % (int)pow(10,index+1);
    }
    std::cout << "" <<std::endl;

    while(list.size() > 1){
        std::cout << list.front() << " " << list.back() << std::endl;
        if(list.front() != list.back())
            return false;
        list.pop_front();
        list.pop_back();
    };
    return true;
};

int main(){

    bool is_true = isPalindrome(1234321);

    std::cout << "Is is a palindrome?.....  " << is_true << std::endl;


    return 0;
};