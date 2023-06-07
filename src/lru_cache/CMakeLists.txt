cmake_minimum_required(VERSION 3.5)
cmake_policy(SET CMP0074 NEW)

project(lru_cache LANGUAGES CXX)
set(PROJECT_NAME lru)
set (CMAKE_CXX_STANDARD 17)

set(SOURCES_DIR ${CMAKE_SOURCE_DIR}/src/lru_cache)

add_executable(${PROJECT_NAME}
			   ${SOURCES_DIR}/lru_cache.hpp
			   ${SOURCES_DIR}/lru_cache_example.cpp
)
			   
target_include_directories(${PROJECT_NAME} PRIVATE ${SOURCES_DIR})
