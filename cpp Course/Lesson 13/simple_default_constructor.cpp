#include <iostream>
#include <string>
#include <vector>
#include "simple_default_constructor.h"

using namespace std; //Note that this is not always a good idea to use all of std

int main(){
    Player marcy; //Will use the only constructor we have but default all parameters     
    marcy.xp = 55;
    Player *laure = new Player("Laure"); //Create Player object on the heap
    cout << "Laure xp: " << laure->xp << endl; //Using member of a pointer operator


    Player players[] {marcy, marcy};
    players[1] = *laure; // assigning the value of where the laure pointer is pointing to
    vector<Player> player_vec {marcy};
    player_vec.push_back(*laure); // same here if we change laure then both of these array/vectors wont change

    // Because *laure was pushed into the vector we can use a dot operator on that object
    cout << "Laure health: " << player_vec[1].health_check() << endl;
    laure->change_health(-200);
    cout << "Laure (in vector) health after -200: " << player_vec[1].health_check() << endl;
    cout << "Laure (in array) health after -200: " << players[1].health_check() << endl;
    cout << "Laure (object) health after -200: " << laure->health_check() << endl;

    player_vec[1].change_health(-101);
    for (auto player:player_vec){
        player.talk();
        cout << "Player Alive?: " << !player.is_dead() << endl;
    }

    return 0;
}

//unlike the oop example here we just set one constructor with defaults so that we only need to write it once
Player::Player(string _name, int life, int _xp) : name{_name}, health{life}, xp{_xp}{
};

Player::~Player(){
    cout << "Destroying object..." << endl;
};

void Player::talk(){
    cout << "My name is " << name << endl;
};

int Player::health_check(){
    return health;
};

bool Player::is_dead(){
    return (health < 1);
};

void Player::change_health(int change){
    health += change;
};