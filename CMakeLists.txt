cmake_minimum_required(VERSION 2.8.4)
project(moka_engine)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -msse -msse2 -msse3 -std=c++11")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "C:/Users/Shelo/Git/moka-engine")

if(WIN32)
	add_definitions(-DWIN32)
endif()

if(UNIX)
	add_definitions(-DUNIX)
endif()

file(GLOB_RECURSE HDRS ./src/*.h)
file(GLOB_RECURSE SRCS ./src/*.cpp)

include_directories(include/ src/)

set(SOURCE_FILES Main.cpp)
add_executable(moka_engine ${SOURCE_FILES} ${HRDS} ${SRCS})

link_directories(lib/)
target_link_libraries(moka_engine glfw3.dll.a glew32s.lib opengl32.lib)