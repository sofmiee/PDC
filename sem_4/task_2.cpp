#include <thread>
#include <iostream>
#include <vector>
#include "Account.h"
#include "Bank.h"

int main() {
    std::vector<Account<int>> accounts;
    Bank<int> bank;

    int n_accounts;
    std::vector <std::thread> users;
    std::cout << "Введите количество клиентов: " << std::endl;
    std::cin >> n_accounts;

    for (int i = 1; i <= n_accounts; i++) {
        int start_balance;
        std::cout << "Введите баланс " << i << " клиента: ";
        std::cin >> start_balance;

        bank.add_account(start_balance, i);

    }

    std::thread user_1(bank.transfer(1, 5, 30));
}