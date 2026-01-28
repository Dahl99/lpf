cmake_minimum_required(VERSION 3.12)

project(lpf)

set(SOURCES
        main.cpp
        LowpassFilter.cpp
)

add_executable(lpf ${SOURCES})

target_compile_features(
        ${PROJECT_NAME}
        PRIVATE
        cxx_std_20
)