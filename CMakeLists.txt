cmake_minimum_required(VERSION 3.3)
project(virtual)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -Wno-pmf-conversions")

set(ROOT_DIR ${PROJECT_SOURCE_DIR})

include_directories(
  ${ROOT_DIR}
)

function (exe_generator name)
  set(GEN_DIR ${ROOT_DIR}/${name})
  include_directories(
    ${GEN_DIR} 
  )
  file(GLOB_RECURSE GEN_SRC *.hpp *.cpp)
  add_executable(${name} ${GEN_SRC})
  set_target_properties(${name} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${ROOT_DIR}/bin
  )
endfunction()

add_subdirectory(virtual)
