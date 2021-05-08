#include <iostream>

using namespace std;

void function (int *pointer);
int *display (int *array, int sentinel);
int *create_array(int size, int init_value = 0);

int main()
{
    int value {100};
    int *pointer {nullptr};

    cout << "Value: " << value << endl;
    function(&value); //pass by reference is passing a pointer!!
    cout << "Value: " << value << endl;

    pointer = &value;
    cout << "Pointer: " << *pointer << endl;
    function(pointer); //pass through pointer
    cout << "Pointer: " << *pointer << endl;
    cout << "Value at the end is: " << value << endl;


    int scores[] {100, 98, 97, 91, 88, 82, -1};
    int *array_size = display(scores, -1);
    cout << "array size is: " << *array_size << endl;

    int *array_pointer = create_array(3, 99);
    cout << *(array_pointer) << endl;
    cout << *(array_pointer + 1) << endl;
    cout << *(array_pointer + 2) << endl;
    cout << *(array_pointer + 3) << endl;

    return 0;
}

int *display (int *array, int sentinel){
    int *size_pointer {nullptr};
    size_pointer = new int {0};

    while (*array != sentinel)
    {
        (*size_pointer)++;
        cout << *array++ << " ";
    }
    cout << endl;

    return size_pointer;
}

int *create_array(int size, int init_value){
    int *new_storage {nullptr};
    new_storage = new int[size];
    for(int i = 0; i < size; ++i){
        *(new_storage + i) = init_value;
    }
    return new_storage;
}

void function (int *pointer){
    *pointer = *pointer + 4;
}