#include <iostream>
#include "account.h"
#include "savings_account.h"

using namespace std;

int main(){
    cout << "Inheritance section" << endl;

    cout<< "=== Account ==================================" << endl;
    Account acc;
    acc.deposit(200.0);
    acc.withdraw(100);

    Account *p_acc = new Account();
    p_acc->deposit(250);
    p_acc->withdraw(150);
    delete p_acc; //this deletes/frees up allocated memory

    cout<< "\n=== Savings_Account ==================================" << endl;
    Savings_Account s_acc;
    s_acc.deposit(200.0);
    s_acc.withdraw(100);

    Savings_Account *p_s_acc = new Savings_Account();
    p_s_acc->deposit(250);
    p_s_acc->withdraw(150);
    delete p_s_acc; //this deletes/frees up allocated memory

    return 0;
};