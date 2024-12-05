cmake_minimum_required(VERSION 3.12.0)
project(eventbus VERSION 0.1.0 LANGUAGES C)

add_library(eventbus src/eventbus.c)

include(CTest)
enable_testing()
