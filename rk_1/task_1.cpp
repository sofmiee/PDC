#include "Storage.h"
#include <thread>
#include <chrono>
#include <iostream>

Storage zone_1(1, 10, 100);
Storage zone_2(2, 3, 150);

int main() {
    std::cout << "Зона №1" << std::endl << "В наличии: " << zone_1.get_amount() << std::endl
    << "Необходимо: " << zone_1.get_need_amount() << std::endl;

    std::cout << "Зона №2" << std::endl << "В наличии: " << zone_2.get_amount() << std::endl
 << "Необходимо: " << zone_2.get_need_amount() << std::endl;

    std::thread Inspector([] {
        while (!zone_1.full() || !zone_2.full()) {
            zone_1.check();
            zone_2.check();
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    });

    std::thread Refiller([] {
        while (!zone_1.full() || !zone_2.full()) {
            zone_1.add();
            zone_2.add();
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    });



    Inspector.join();
    Refiller.join();

    std::cout << "Зона №1" << std::endl << "В наличии: " << zone_1.get_amount() << std::endl
    << "Необходимо: " << zone_1.get_need_amount() << std::endl;

    std::cout << "Зона №2" << std::endl << "В наличии: " << zone_2.get_amount() << std::endl
 << "Необходимо: " << zone_2.get_need_amount() << std::endl;
    return 0;
}

