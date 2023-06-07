cmake_minimum_required(VERSION 3.5)
cmake_policy(SET CMP0074 NEW)

project(algorithms LANGUAGES CXX)
set(PROJECT_NAME algorithms)
set (CMAKE_CXX_STANDARD 17)

set(SOURCES_DIR ${CMAKE_SOURCE_DIR}/src)

add_subdirectory(${SOURCES_DIR}/binary_search)
add_subdirectory(${SOURCES_DIR}/lru_cache)
			   
#target_include_directories(${PROJECT_NAME} PRIVATE ${SOURCES_DIR})
