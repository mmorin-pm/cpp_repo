#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <string>

class Player
{
    //attributes (data)
private: //These will not be accessible to someone using the Player class
    std::string name; //will not give us garbage as it has a default constructor
    int health;

public:
    Player(); // no args contructor
    Player(std::string _name); //As soon as we define a construction cpp does not give us a free no args construction anymore so we have to define that if we want it
    Player(std::string _name, int health);
    ~Player(); // only destructor allowed per class (Can't be overloaded)
    int xp;
    //methods (functions definition)
    void change_health(int change);
    void talk();
    int health_check();
    bool is_dead();
};

#endif