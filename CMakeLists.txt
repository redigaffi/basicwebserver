cmake_minimum_required(VERSION 3.12)
project(WebServer)

set(CMAKE_CXX_STANDARD 17)

add_executable(WebServer src/main.cpp src/socket/SocketServer.cpp src/socket/SocketServer.h)