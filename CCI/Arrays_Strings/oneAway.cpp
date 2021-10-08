#include <iostream>

// There are 3 types of edits that can be preformed on strings: insert, replace, remove (of a character)
// Given two strings write a function to check if they are one edit away.

bool checkReplacement(std::string word1, std::string word2){
    int diff = 0;
    for(int i = 0; i < word1.size(); i++){
        if((word1[i] != word2[i]) && diff)
            return false;
        if(word1[i] != word2[i])
            diff++;
    }
    return true;
}

bool checkInsert(std::string word1, std::string word2){
    int diff = 0;
    for(int i = 0; i < word1.size(); i++){
        if((word1[i] != word2[i+diff]) && diff)
            return false;
        if(word1[i] != word2[i]){
            if(word1[i] != word2[i+1])
                return false;
            else
                diff++;
        }
    }  
    return true;
}

bool oneAway(std::string word1, std::string word2){
    std::cout << word1 << ", " << word2 << std::endl;
    if(word1 == word2) return true;
    if(word1.size() == word2.size())
        return checkReplacement(word1,word2);
    if(word1.size() == (word2.size()-1))
        return checkInsert(word1,word2);
    if(word1.size() == (word2.size()+1))
        return checkInsert(word2,word1);

    return false;
}



int main(){

    if(oneAway("bale","pale"))
        std::cout << "True" << std::endl;
    else 
        std::cout << "False" << std::endl;

    if(oneAway("aabaa","aaaa"))
        std::cout << "True" << std::endl;
    else 
        std::cout << "False" << std::endl;

    if(oneAway("abcdef","abcdgef"))
        std::cout << "True" << std::endl;
    else 
        std::cout << "False" << std::endl;

    if(oneAway("a","ab"))
        std::cout << "True" << std::endl;
    else 
        std::cout << "False" << std::endl;

    return 0;
}