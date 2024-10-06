cmake_minimum_required(VERSION 3.29)
project(simple_paint)

set(CMAKE_CXX_STANDARD 23)

add_executable(simple_paint main.cpp
        Shape.h
        Rectangle.cpp
        Rectangle.h
        Board.cpp
        Board.h
        Line.cpp
        Line.h
        Circle.cpp
        Circle.h)
