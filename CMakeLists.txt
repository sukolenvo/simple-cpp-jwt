cmake_minimum_required(VERSION 3.22.1)

project(simple-cpp-jwt VERSION 1.0)

cmake_policy(SET CMP0048 NEW)

add_library(simple-cpp-jwt-compiler-options INTERFACE)
target_compile_features(simple-cpp-jwt-compiler-options INTERFACE cxx_std_20)

add_subdirectory(vendor/CLI11)
add_subdirectory(vendor/simple-cpp-base64)

add_executable(simple-jwt-tool main.cpp)
target_link_libraries(simple-jwt-tool CLI11::CLI11 simple-cpp-base64::lib simple-cpp-jwt-compiler-options)
set_target_properties(simple-jwt-tool PROPERTIES OUTPUT_NAME simple-jwt-${CMAKE_PROJECT_VERSION}-${CMAKE_SYSTEM_NAME}-${CMAKE_CXX_COMPILER_ID}-${CMAKE_CXX_COMPILER_VERSION})

enable_testing()
add_test(NAME jwt-decode COMMAND simple-jwt-tool eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJzdWIiOiIxMjM0NTY3ODkwIiwibmFtZSI6IkpvaG4gRG9lIiwiaWF0IjoxNTE2MjM5MDIyfQ.SflKxwRJSMeKKF2QT4fwpMeJf36POk6yJV_adQssw5c)
set_property(TEST jwt-decode PROPERTY PASS_REGULAR_EXPRESSION ".*1234567890.*John Doe.*")