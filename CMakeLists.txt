cmake_minimum_required(VERSION 3.10)

set(CXX_STANDARD 17)

project(server)

include_directories(
        ${PROJECT_SOURCE_DIR}/src
)

file(GLOB all_SRCS
        "${PROJECT_SOURCE_DIR}/src/*.cpp"
)


add_executable(app ${all_SRCS})