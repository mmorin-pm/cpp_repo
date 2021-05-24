#ifndef _MOVIE_H_
#define _MOVIE_H_

#include <string>

class Movie
{
    private:
        std::string name;
        std::string rating;
        int watched;
    public:
        Movie(std::string name = "<movie name>", std::string rating = "R", int watched = 0);
        std::string get_name() const;
        std::string get_rating() const;
        int get_watched() const;
        void increment_watched();
};

#endif