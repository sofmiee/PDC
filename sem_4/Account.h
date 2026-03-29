#ifndef SEM_4_ACCOUNT_H
#define SEM_4_ACCOUNT_H

#include <iostream>

template <class T>
class Account {
private:
    int id_account;
    T balance = T(0);
public:
    Account(T start_balance, int id_account);
    T get_balance();
    void deposit (T amount);
    void withdraw (T amount);
};

template <class T>
Account<T>::Account(T start_balance, int id_account) {
    this -> balance = start_balance;
    this->id_account = id_account;
}

template <class T>
T Account<T>::get_balance() {
    return balance;
}

template <class T>
void Account<T>::deposit(T amount) {
    balance += amount;
}

template <class T>
void Account<T>::withdraw(T amount) {
    if (balance - amount >= 0) {
        balance -= amount;
    }
    std::cout << "Недостаточно средств.";

}


#endif //SEM_4_ACCOUNT_H