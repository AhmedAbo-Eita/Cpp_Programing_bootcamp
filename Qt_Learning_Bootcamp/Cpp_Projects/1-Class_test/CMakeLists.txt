cmake_minimum_required(VERSION 3.16)

project(1-Class_test LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(1-Class_test main.cpp)

include(GNUInstallDirs)
install(TARGETS 1-Class_test
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
