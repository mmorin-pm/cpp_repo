#include <iostream>
#include "movies.h"

Movies::Movies() {
};
Movies::~Movies() {
};
void Movies::display() const{
    for(auto movie: list)
        cout << movie.get_name() << ", ";
    cout << "" << endl;
};
bool Movies::increment_watched(std::string name){
    for(auto movie: list){
        if(movie.get_name() == name){
            movie.increment_watched();
            return true;
        }
    }
    return false;
};
bool Movies::add_movie(std::string name, std::string rating, int watched){
    for(auto movie: list){
        if(movie.get_name() == name)
            return false;
    }
    Movie temp {name, rating, watched};
    list.push_back(temp);
    return true;
};