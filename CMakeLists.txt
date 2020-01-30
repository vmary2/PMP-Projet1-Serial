cmake_minimum_required(VERSION 3.10)

project(SIG
  LANGUAGES CXX
)

find_package(Threads)

add_executable(testSignal
  testSignal.cc
  googletest/googletest/src/gtest-all.cc
)

target_include_directories(testSignal
  PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/googletest/googletest/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/googletest/googletest"
)

target_link_libraries(testSignal
  PRIVATE
    Threads::Threads
)

target_compile_options(testSignal
  PRIVATE
    "-Wall" "-Wextra" "-g" "-O2"
)

target_compile_features(testSignal
  PUBLIC
    cxx_std_17
)

set_target_properties(testSignal
  PROPERTIES
    CXX_EXTENSIONS OFF
)
