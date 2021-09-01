#include <iostream>
#include "savings_account.h"

Savings_Account::Savings_Account(){

};

Savings_Account::~Savings_Account(){

};

void Savings_Account::deposit(double amount){
    std::cout << "Savings_Account deposit called with " << amount  << std::endl;
};

void Savings_Account::withdraw(double amount) {
    std::cout << "Savings_Account withdraw called with " << amount  << std::endl;
};
