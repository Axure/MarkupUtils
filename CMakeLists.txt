cmake_minimum_required(VERSION 3.2)
project(MarkupUtils)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
set(NODE_TEST_FIELS test/NodeTest.cpp)

set(LIB_FILES Syntax.cpp Syntax.h Converter.cpp Converter.h Parser.cpp Parser.h Node.cpp Node.hpp Tree.cpp Tree.h)

add_executable(MarkupUtils ${SOURCE_FILES} ${LIB_FILES})
set_target_properties(MarkupUtils PROPERTIES LINK_FLAGS "-lboost_regex")

add_executable(NodeTest ${NODE_TEST_FIELS} ${LIB_FILES})
set_target_properties(NodeTest PROPERTIES LINK_FLAGS "-lboost_regex")