#ifndef _MOVIES_H_
#define _MOVIES_H_

#include <string>
#include <vector>
#include "movie.h"

using namespace std;

class Movies
{
    private:
        std::vector<Movie> list;
    public:
        void display() const;
        bool increment_watched(std::string name);
        bool add_movie(std::string name, std::string rating, int watched);
};

#endif