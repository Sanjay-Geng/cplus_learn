cmake_minimum_required(VERSION 3.8)
project(lib-test)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11") # 编译选项

set(ROOT_DIR ${PROJECT_SOURCE_DIR})   # 定义根目录变量

include_directories(
  ${ROOT_DIR}/include
)

function (exe_generator name)
  include_directories(
    ${CMAKE_CURRENT_LIST_DIR} 
  )
  file(GLOB_RECURSE FILE_SRC *.cpp)
  add_executable(${name} ${FILE_SRC})
  target_link_directories(${name} PRIVATE ${ROOT_DIR}/lib)
  target_link_libraries(${name} mylib)
  set_target_properties(${name} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${ROOT_DIR}/bin
  )
endfunction()

function (lib_generator name)
  include_directories(
    ${CMAKE_CURRENT_LIST_DIR} 
  )
  file(GLOB_RECURSE FILE_SRC *.cpp)
  add_library(${name} STATIC ${FILE_SRC})
  set_target_properties(${name} PROPERTIES
    #LIBRARY_OUTPUT_DIRECTORY ${ROOT_DIR}/lib
    ARCHIVE_OUTPUT_DIRECTORY ${ROOT_DIR}/lib
  )
endfunction()

add_subdirectory(src)
add_subdirectory(include)