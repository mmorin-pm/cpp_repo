#include <iostream>
#include "shallow_copy.h"

void display_shallow(Shallow object);

int main(){

    Shallow obj1 {100};
    std::cout << *obj1.data << std::endl;
    display_shallow(obj1); // As we leave this scope the pointer is also released but we still need it

    std::cout << *obj1.data << std::endl; // This is display released memory/garbage

    return 0;
}

Shallow::Shallow(int d){
    data = new int; //allocate storage
    *data = d;
};

Shallow::~Shallow(){
    delete data;
    std::cout << "Destructor freeing data" << std::endl;
};

Shallow::Shallow(const Shallow &source) : data{source.data}{
    std::cout << "Copy Constructor - shallow" << std::endl;
};

void display_shallow(Shallow object){
    std::cout << *(object.data) << std::endl;
};