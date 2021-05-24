#include <iostream>
#include "movie.h"

std::string Movie::get_name() const{
    return name;
};
std::string Movie::get_rating() const{
    return rating;
};
int Movie::get_watched() const{
    return watched;
};
void Movie::increment_watched(){
    watched++;
};
