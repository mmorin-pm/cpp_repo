#include <iostream>
#include <string>
#include <vector>
#include "oop.h"

using namespace std; //Note that this is not always a good idea to use all of std

int Player::num_players {0};

void display_players(){
    cout << "       Active Players: " << Player::get_num_players() << endl;
};

int main(){
    Player marcy {"Marcel"};      
    // Because these are private we can't access them here
    // marcy.name = "Marcel";
    // marcy.health = 99;
    marcy.xp = 55;
    Player *laure = new Player("Laure"); //Create Player object on the heap
    cout << "Laure xp: " << laure->xp << endl; //Using member of a pointer operator
    display_players();

    Player players[] {marcy, marcy};
    display_players();
    players[1] = *laure; // assigning the value of where the laure pointer is pointing to

    vector<Player> player_vec {marcy};
    display_players();
    player_vec.push_back(*laure); // same here if we change laure then both of these array/vectors wont change
    display_players();
    // Because *laure was pushed into the vector we can use a dot operator on that object
    cout << "Laure health: " << player_vec[1].health_check() << endl;
    laure->change_health(-200);
    cout << "Laure (in vector) health after -200: " << player_vec[1].health_check() << endl;
    cout << "Laure (in array) health after -200: " << players[1].health_check() << endl;
    cout << "Laure (object) health after -200: " << laure->health_check() << endl;

    cout << "Starting loop." << endl;
    player_vec[1].change_health(-101);
    for (auto player:player_vec){
        player.talk();
        cout << "Player Alive?: " << !player.is_dead() << endl;
    }
    cout << "Finihed loop." << endl;
    delete laure;
    return 0;
}

// Player::Player(){ //no args constructor
//     name = "<player_name>";
//     health = -1;
//     xp = 0;
// };
// Using initialization lists bellow is better than what we do above
Player::Player() : name{"<player_name>"}, health{-1}, xp{0}{
    num_players++;
}; //Using constructor initialization lists

Player::Player(string _name) : Player {_name, 100}{
}; // Delegating constructor to the one bellow (easy and reuses code)

Player::Player(string _name, int life) : name{_name}, health{life}, xp{0}{
    num_players++;
};

Player::~Player(){
    cout << "Destroying object... name: " << name << endl;
    num_players--;
};

//Player::Player(const Player &source) : name{source.name}, health{source.health}, xp{source.xp}{
    // can also delegate constructor : 
Player::Player(const Player &source) : Player {source.name, source.health}{
    cout << "Copying object: " << name << endl;
};

void Player::talk() const{
    cout << "My name is " << name << endl;
};

int Player::health_check() const{
    return health;
};

bool Player::is_dead() const{
    return (health < 1);
};

void Player::change_health(int change){
    health += change;
};

int Player::get_num_players(){
    return num_players;
};