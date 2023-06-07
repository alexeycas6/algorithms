cmake_minimum_required(VERSION 3.5)
cmake_policy(SET CMP0074 NEW)

project(binary_search LANGUAGES CXX)
set(PROJECT_NAME binary_search)
set (CMAKE_CXX_STANDARD 17)

set(SOURCES_DIR ${CMAKE_SOURCE_DIR}/src/binary_search)
add_executable(${PROJECT_NAME}
			   ${SOURCES_DIR}/binary_search.hpp
			   ${SOURCES_DIR}/binary_search_example.cpp
)
			   
target_include_directories(${PROJECT_NAME} PRIVATE ${SOURCES_DIR})
