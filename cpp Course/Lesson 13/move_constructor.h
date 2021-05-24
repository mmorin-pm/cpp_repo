#ifndef _MOVE_H_
#define _MOVE_H_

class Move {
    private:
        int *data;
    public:
    void set_data_value(int d) { *data = d; }
    int get_data_value() {return *data; }
    Move(int d); // constructor
    Move(const Move &source); //Copy Constructor
    Move(Move &&source) noexcept; //Move Constructor
    ~Move(); //Destructor
};

#endif