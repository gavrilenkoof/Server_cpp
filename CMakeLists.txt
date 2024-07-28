cmake_minimum_required(VERSION 3.10)

set(CXX_STANDARD 17)

project(server VERSION 1.0 LANGUAGES CXX)


set(CMAKE_CXX_FLAGS -pthread)

# executable
set(SOURCE_EXE src/main.cpp)
add_executable(app ${SOURCE_EXE})



# add boost
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.45.0 COMPONENTS filesystem regex)
include_directories(${Boost_INCLUDE_DIRS})


#targets link
add_subdirectory(lib EXCLUDE_FROM_ALL)
target_include_directories(app PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}"
                          )


target_link_libraries(app PUBLIC    server 
                                    server_boost 
                                    ${Boost_LIBRARIES})