cmake_minimum_required(VERSION 3.1)

project(wrapper_c CXX)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")
set(LIBS)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON) 
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_FLAGS "-I${CMAKE_CURRENT_SOURCE_DIR}/../../")

find_package(MPI REQUIRED)
  if (MPI_FOUND)
    include_directories(SYSTEM ${MPI_CXX_INCLUDE_PATH})
  else()
    message(SEND_ERROR "MPI not found")
endif()

file(GLOB source3d  ${CMAKE_CURRENT_SOURCE_DIR}/mui_3d.cpp)
file(GLOB source2d  ${CMAKE_CURRENT_SOURCE_DIR}/mui_2d.cpp)
file(GLOB source1d  ${CMAKE_CURRENT_SOURCE_DIR}/mui_1d.cpp)

add_library(muiwrapper3d_c STATIC ${source3d})
add_library(muiwrapper2d_c STATIC ${source2d})
add_library(muiwrapper1d_c STATIC ${source1d})


