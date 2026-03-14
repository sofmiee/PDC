cmake_minimum_required(VERSION 3.10)
project(sem_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(sem_2 task_1.cpp
        task_2.cpp
        task_3.cpp
        task_4.cpp
        task_5.cpp
        task_6.cpp
        task_7.cpp
        task_8.cpp
        task_9.cpp
        task_10_11/FileManager.cpp
        task_10_11/Group.cpp
        task_10_11/main.cpp
        task_10_11/Person.cpp
        task_10_11/Student.cpp
        task_10_11/Teacher.cpp
)

if (WIN32)
    # Windows + MinGW
    message("-- Configuring for Windows (MinGW)")

    # Пути к заголовкам и библиотекам
    target_include_directories(sem_2 PRIVATE "C:/local/boost_1_87_0")
    target_link_directories(sem_2 PRIVATE "C:/local/boost_1_87_0/stage/lib")

    # Имена библиотек (Windows)
    target_link_libraries(sem_2
            boost_thread-mgw13-mt-x64-1_87
            boost_system-mgw13-mt-x64-1_87
    )
elseif (UNIX)
    # Linux/WSL
    message("-- Configuring for Linux/WSL")

    # Флаг для потоков
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

    # Автоматический поиск Boost (установлен через apt)
    find_package(Boost REQUIRED COMPONENTS thread system)
    target_link_libraries(sem_2 PRIVATE
            Boost::thread
            Boost::system
    )
endif()
