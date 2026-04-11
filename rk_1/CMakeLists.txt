cmake_minimum_required(VERSION 3.10)
project(rk_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(rk_1
        task_1.cpp
        task_2.cpp
        Inspector.cpp
        Inspector.h
        Storage.cpp
        Storage.h
)

if (WIN32)
    # Windows + MinGW
    message("-- Configuring for Windows (MinGW)")

    # Пути к заголовкам и библиотекам
    target_include_directories(rk_1 PRIVATE "C:/local/boost_1_87_0")
    target_link_directories(rk_1 PRIVATE "C:/local/boost_1_87_0/stage/lib")

    # Имена библиотек (ДОБАВИЛА boost_chrono!)
    target_link_libraries(rk_1
            boost_thread-mgw13-mt-x64-1_87
            boost_chrono-mgw13-mt-x64-1_87      # ← Добавлено!
            boost_system-mgw13-mt-x64-1_87
    )
elseif (UNIX)
    # Linux/WSL
    message("-- Configuring for Linux/WSL")

    # Флаг для потоков
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

    # Автоматический поиск Boost (ДОБАВИЛА chrono!)
    find_package(Boost REQUIRED COMPONENTS thread chrono system)  # ← Добавлен chrono

    target_link_libraries(rk_1 PRIVATE
            Boost::thread
            Boost::chrono    # ← Добавлено!
            Boost::system
    )
endif()