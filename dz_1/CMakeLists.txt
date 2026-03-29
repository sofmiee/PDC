cmake_minimum_required(VERSION 3.10)
project(dz_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(dz_1
        main.cpp
        Tasks.cpp
        Tasks.h
        Queue.cpp
        Queue.h
        Thread.cpp
        Thread.h
)

if (WIN32)
    # Windows + MinGW
    message("-- Configuring for Windows (MinGW)")

    # Пути к заголовкам и библиотекам
    target_include_directories(dz_1 PRIVATE "C:/local/boost_1_87_0")
    target_link_directories(dz_1 PRIVATE "C:/local/boost_1_87_0/stage/lib")

    # Имена библиотек (ДОБАВИЛА boost_chrono!)
    target_link_libraries(dz_1
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

    target_link_libraries(dz_1 PRIVATE
            Boost::thread
            Boost::chrono    # ← Добавлено!
            Boost::system
    )
endif()