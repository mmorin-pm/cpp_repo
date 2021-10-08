#include <iostream>

bool isRotation(std::string s1, std::string s2){
    std::string s1s1 = s1 + s1;
    if(s1s1.find(s2) != std::string::npos)
        return true;
    return false;
}

int main(){

    if(isRotation("stringone", "onestring"))
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;
}