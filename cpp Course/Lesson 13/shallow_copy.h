#ifndef _COPY_H_
#define _COPY_H_

class Shallow {
    public:
        int *data;
        Shallow(int d); //Constructor
        Shallow(const Shallow &source); //Copy
        ~Shallow();
};

#endif