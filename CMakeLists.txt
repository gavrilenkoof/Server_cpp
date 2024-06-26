cmake_minimum_required(VERSION 3.10)

set(CXX_STANDARD 17)

project(server VERSION 1.0 LANGUAGES CXX)


# executable
set(SOURCE_EXE src/main.cpp)
add_executable(app ${SOURCE_EXE})


#targets link
add_subdirectory(lib EXCLUDE_FROM_ALL)
target_link_libraries(app PUBLIC server)
target_include_directories(app PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}"
                          )

