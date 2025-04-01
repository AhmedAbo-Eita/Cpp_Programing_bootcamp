cmake_minimum_required(VERSION 3.16)

project(2-ClassesConstructors LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(2-ClassesConstructors main.cpp)

include(GNUInstallDirs)
install(TARGETS 2-ClassesConstructors
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
