cmake_minimum_required(VERSION 2.6)
project(SFML-Game)

set(CMAKE_CXX_FLAGS "-g -Wall")
set(EXECUTABLE_NAME "SFMLGame")
set(CMAKE_MODULE_PATH "/usr/share/SFML/cmake/Modules/" ${CMAKE_MODULE_PATH})

add_executable(${EXECUTABLE_NAME} main.cpp)

find_package(SFML 2 REQUIRED system window graphics)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()
