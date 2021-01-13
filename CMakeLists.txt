cmake_minimum_required(VERSION 3.0.0)
project(atm)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

add_executable(atm
               Account.cxx
               ATM.cxx
               Bank.cxx
               BaseDisplay.cxx
               Main.cxx)

target_include_directories(atm PRIVATE include)
