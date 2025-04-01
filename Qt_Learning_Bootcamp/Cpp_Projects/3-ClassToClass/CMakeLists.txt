cmake_minimum_required(VERSION 3.16)

project(3-ClassToClass LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(3-ClassToClass main.cpp)

include(GNUInstallDirs)
install(TARGETS 3-ClassToClass
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
