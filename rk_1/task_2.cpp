#include <iostream>
#include <thread>
#include <semaphore>
#include <chrono>

std::counting_semaphore<1> sem_load_to_process(0);   // для этапа B
std::counting_semaphore<1> sem_process_to_pack(0);   // для этапа C

void stage_load() {
    std::cout << "Начало загрузки материала" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Загрузка завершена!" << std::endl;

    sem_load_to_process.release();
}

void stage_process() {
    sem_load_to_process.acquire();
    
    std::cout << "Начало обработки материала" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << "Обработка завершена!" << std::endl;

    sem_process_to_pack.release();
}

void stage_pack() {
    sem_process_to_pack.acquire();
    
    std::cout << "Начало упаковки продукта" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Упаковка завершена!" << std::endl;
}

int main() {
    std::thread t1(stage_load);
    std::thread t2(stage_process);
    std::thread t3(stage_pack);
    
    t1.join();
    t2.join();
    t3.join();
    
    std::cout << "\nВсе этапы выполнены!" << std::endl;
    
    return 0;
}