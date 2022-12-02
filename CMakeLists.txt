cmake_minimum_required(VERSION 3.17)
project(TheSleepingSantaClaus)

set(CMAKE_CXX_STANDARD 14)

add_executable(TheSleepingSantaClaus main.cpp cmake-build-debug/SantaClaus.cpp cmake-build-debug/SantaClaus.h cmake-build-debug/Reindeer.cpp cmake-build-debug/Reindeer.h cmake-build-debug/Elf.cpp cmake-build-debug/Elf.h)