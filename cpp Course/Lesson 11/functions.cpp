#include <iostream>
#include <string>

using namespace std;

int read_input();
int process_input(int a = 1);
void provide_output(int a);
void static_function_var();

int main()
{
    int value = read_input();
    value = process_input(value);
    provide_output(value);

    static_function_var();
    static_function_var();
    static_function_var();

    return 0;
}

int read_input(){
    int input;
    cin >> input;
    return input;
}
int process_input(int a){
    return a*10;
}
void provide_output(int a){
    cout << "Your number x10 is " << a << endl;
}

void static_function_var(){
    static int num = 75; // num is only initialized once and will retain its updated value everytime the function is called
    num = num + 25;
    cout << num << endl;
}