cmake_minimum_required(VERSION 4.0)
project(Lost_Island)

include(FetchContent)
set(BUILD_SHARED_LIBS OFF)
FETCHCONTENT_DECLARE(SFML GIT_REPOSITORY https://github.com/SFML/SFML.git GIT_TAG 3.0.2)
FETCHCONTENT_MAKEAVAILABLE(SFML)

set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(Lost_Island src/main.cpp)

target_include_directories(Lost_Island PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_link_libraries(Lost_Island sfml-system sfml-graphics sfml-audio sfml-window)
