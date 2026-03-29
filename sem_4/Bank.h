#ifndef SEM_4_BANK_H
#define SEM_4_BANK_H

#include <vector>
#include "Account.h"
#include <mutex>
#include <condition_variable>

template <class T>
class Bank {
private:
    std::mutex mtx;
    std::condition_variable cv;
    std::vector <Account<T>> accounts;
public:
    Bank();
    inline void transfer(int to, int from, T amount);
    void add_account(T start_balance, int id);
};

template <class T>
Bank<T>::Bank()= default;

template <class T>
void Bank<T>::add_account(T start_balance, int id) {
    Account<T> acc(start_balance, id);
    accounts.push_back(acc);
}


template <class T>
inline void Bank<T>::transfer(int to, int from, T amount) {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [this, from, amount]{return amount <= accounts[from].get_balance();});
    accounts[from].withdraw(amount);
    accounts[to].deposit(amount);
    cv.notify_all();
}

#endif //SEM_4_BANK_H