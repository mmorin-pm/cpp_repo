#include <iostream>
#include <string>
#include <vector>


using namespace std; //Note that this is not always a good idea to use all of std

class Player
{
    //attributes (data)
public: //By default these would be private and not accessible when using the object outside of this class
    string name {"player"};
    int health {100};
    int xp {5};

    //methods (functions)
    void talk(){
        cout << "My name is " << name << endl;
    };
    bool is_dead(){
        return (health < 1);
    };
};

int main(){
    Player marcy; // health and xp are not initialized so its garbage data
                  // name has a default initializer so its good
    marcy.name = "Marcel";
    marcy.health = 99;
    marcy.xp = 55;
    Player *laure = new Player(); //Create Player object on the heap
    cout << "Laure xp: " << laure->xp << endl; //Using member of a pointer operator


    Player players[] {marcy, *laure};
    vector<Player> player_vec {marcy};
    player_vec.push_back(*laure);

    // Because *laure was pushed into the vector we can use a dot operator on that
    cout << "Laure health:" << player_vec[1].health << endl;

    for (auto player:player_vec){
        player.talk();
        cout << "Player Alive?: " << player.is_dead() << endl;
    }

    return 0;
}
