#ifndef _COPY_H_
#define _COPY_H_

class Deep {
    private:
        int *data;
    public:
        Deep(int d); //Constructor
        Deep(const Deep &source); //Copy
        ~Deep();
        int get_data();
};

#endif