cmake_minimum_required(VERSION 3.10)

project(SERIAL
  LANGUAGES CXX
)

find_package(Threads)

add_library(serial0
  Serial.cc
)

target_compile_options(serial0
  PRIVATE
    "-Wall" "-Wextra" "-g" "-O2" "-fsanitize=address,undefined"
)

target_compile_features(serial0
  PUBLIC
    cxx_std_17
)

set_target_properties(serial0
  PROPERTIES
    CXX_EXTENSIONS OFF
    LINK_FLAGS "-fsanitize=address,undefined"
)

add_executable(testSerial
  testSerial.cc
  googletest/googletest/src/gtest-all.cc
)

target_include_directories(testSerial
  PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/googletest/googletest/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/googletest/googletest"
)

target_link_libraries(testSerial
  PRIVATE
    serial0
    Threads::Threads
)

target_compile_options(testSerial
  PRIVATE
    "-Wall" "-Wextra" "-g" "-O2"
)

target_compile_features(testSerial
  PUBLIC
    cxx_std_17
)

set_target_properties(testSerial
  PROPERTIES
    CXX_EXTENSIONS OFF
    LINK_FLAGS "-fsanitize=address,undefined"
)
