#include <iostream>
#include <vector>
#include "move_constructor.h"

int main(){

    int x {100}; //l-value
    int &l_ref = x; //l-value reference 
    l_ref = 10;

    int &&r_ref = 200;
    r_ref = 300;

    //int &&x_ref = x; //compiler error

    std::cout << "Creating vector and pushing onto it.." << std::endl;
    std::vector<Move> vec;
    vec.push_back(Move{10});
    vec.push_back(Move{20});

    return 0;
}

Move::Move(int d){
    data = new int;
    *data = d;
    std::cout << "Calling Constructor for " << d << std::endl;
};

Move::Move(const Move &source){
    data = new int;
    *data = *source.data;
    std::cout << "Calling Copy Constructor" << std::endl;
};

//If noexcept is not defined then there will be a copy done when pushing back on vector
Move::Move(Move &&source) noexcept : data{source.data} {
    std::cout << "Calling Move Constructor and moving "<< *data << std::endl;
    source.data = nullptr;
};

Move::~Move(){
    if(data != nullptr){
        std::cout << "Calling Destructor freeing data for: "<< *data << std::endl;
    } else {
        std::cout << "Calling Destructor freeing data for nullptr" << std::endl;
    }
    delete data;
};