cmake_minimum_required(VERSION 3.22)
project(PhysicsInteractive)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(MillerInc.PhysicsEngine)

#
#set(LIBRARY_PATH ${CMAKE_CURRENT_SOURCE_DIR}/imports/PhysicsEngine/libPhysicsEngine.a)
#set(INCLUDE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/imports/PhysicsEngine/include)

#add_library(PhysicsEngine STATIC IMPORTED)
#set_target_properties(PhysicsEngine PROPERTIES IMPORTED_LOCATION ${LIBRARY_PATH})

#include_directories(${INCLUDE_PATH})

add_executable(PhysicsInteractive main.cpp)

target_link_libraries(PhysicsInteractive PhysicsEngine)