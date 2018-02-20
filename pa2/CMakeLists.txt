cmake_minimum_required(VERSION 3.8)
project(pa2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        arrayclass.cpp
        arrayclass.h
        arrayclassprivate.h
        containertests.cpp
        interpreter.h
        interpreterprivate.h
        interpretersecretfunctions.h
        interpretertest.cpp
        queue.h
        queueprivate.h
        stack.h
        stackprivate.h)

add_executable(pa2 ${SOURCE_FILES})