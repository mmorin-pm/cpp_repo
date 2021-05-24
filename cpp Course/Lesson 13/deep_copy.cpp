#include <iostream>
#include "deep_copy.h"

void display_deep(Deep object);

int main(){

    Deep obj1 {100};
    std::cout << obj1.get_data() << std::endl;
    display_deep(obj1);

    std::cout << obj1.get_data() << std::endl;

    return 0;
}

Deep::Deep(int d){
    data = new int; //allocate storage
    *data = d;
};

Deep::~Deep(){
    delete data;
    std::cout << "Destructor freeing data" << std::endl;
};

// Deep::Deep(const Deep &source){
//     data = new int;
//     *data = *source.data;
//     std::cout << "Copy Constructor - deep" << std::endl;
// };
//We can delegate the above copy constructor with the following
Deep::Deep(const Deep &source) : Deep{*source.data}{
    std::cout << "Copy Constructor - deep" << std::endl;
};

int Deep::get_data(){
    return *data;
};

void display_deep(Deep object){
    std::cout << object.get_data() << std::endl;
};

