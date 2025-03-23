cmake_minimum_required(VERSION 3.0.0)
project(atm)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 11)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  atm
  Account.cxx
  ATM.cxx
  Bank.cxx
  BaseDisplay.cxx
  Main.cxx
)

target_include_directories(atm PRIVATE include)


if(CPPTEST_COVERAGE)
  include(cpptest-coverage.cmake)
endif()

add_executable(
  atm_test
  Account.cxx
  ATM.cxx
  Bank.cxx
  BaseDisplay.cxx
  BankTest.cxx
)

target_include_directories(atm_test PRIVATE include)

target_link_libraries(
  atm_test
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(atm_test XML_OUTPUT_DIR "${CMAKE_BINARY_DIR}/gtest-report")
